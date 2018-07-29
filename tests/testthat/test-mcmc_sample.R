library(igraph)

context("mcmc_sample")

test_that("bad call", {
  g <- make_full_graph(4)
  expect_error(mcmc_sample(
    graph = g,
    module_size = 2,
    times = 5,
    niter = 10
  ))

  V(g)$name <- letters[1:4]
  V(g)$likelihood <- rep(1, 4)
  expect_error(mcmc_sample(graph = g))
  expect_error(mcmc_sample(graph = g, niter = 100))
  expect_error(mcmc_sample(
    graph = g,
    module_size = 2,
    niter = 100
  ))
  expect_error(mcmc_sample(
    graph = g,
    times = 10,
    niter = 100
  ))
  expect_error(mcmc_sample(
    graph = g,
    module_size = 2,
    times = 10
  ))

  prvs_mcmc <-
    mcmc_sample(
      graph = g,
      module_size = 2,
      times = 5,
      niter = 100
    )
  expect_error(mcmc_sample(graph = g, previous_mcmc = prvs_mcmc))
})

test_that("mcmc_sample works", {
  g <- make_full_graph(7)
  V(g)$name <- letters[1:7]
  V(g)$likelihood <- runif(7, 0.5, 2)
  x <-
    mcmc_sample(
      graph = g,
      module_size = 3,
      times = 50,
      niter = 100,
      exp_lh = 0,
      fixed_size = T
    )
  expect_identical(sum(get_frequency(x)), 50 * 3)
})

test_that("module must change in one step", {
  g <- make_full_graph(6)
  V(g)$name <- letters[1:6]
  V(g)$likelihood <- rep(1, 6)
  x <-
    mcmc(mat = matrix(c(T, T, T, F, F, F), nrow = 1), name = V(g)$name)
  y <-
    mcmc_sample(
      graph = g,
      previous_mcmc = x,
      niter = 1,
      exp_lh = 1,
      fixed_size = T
    )
  expect_true(any(get_frequency(x) != get_frequency(y)))

  g <- graph_from_atlas(48)
  V(g)$name <- letters[1:5]
  V(g)$likelihood <- c(3, 3, 2, 3, 2)
  x <- mcmc(mat = matrix(c(F, F, T, F, T), nrow = 1), name = V(g)$name)
  y <-
    mcmc_sample(
      graph = g,
      previous_mcmc = x,
      niter = 1,
      exp_lh = 1,
      fixed_size = T
    )
  expect_true(any(get_frequency(x) != get_frequency(y)))
})

test_that("not reachable vertecies", {
  g <- graph_from_atlas(191)
  V(g)$name <- letters[1:6]
  V(g)$likelihood <- 10 ^ c(8, 4, 8, 8, 8, 0)
  x <-
    mcmc(mat = matrix(c(F, F, F, F, F, T), nrow = 1), name = V(g)$name)
  x <-
    mcmc_sample(
      graph = g,
      previous_mcmc = x,
      niter = 1,
      exp_lh = 1,
      fixed_size = T
    )
  expect_identical(sum(get_frequency(x)[letters[c(1, 3, 4, 5)]]), 0)

  g <- graph_from_atlas(100)
  V(g)$name <- letters[1:6]
  V(g)$likelihood <- 10 ^ c(0, 0, 0, 2, 2, 2)
  x <-
    mcmc(mat = matrix(c(T, T, T, F, F, F), nrow = 1), name = V(g)$name)
  x <-
    mcmc_sample(
      graph = g,
      previous_mcmc = x,
      niter = 1,
      exp_lh = 1,
      fixed_size = T
    )
  expect_identical(sum(get_frequency(x)[letters[c(5, 6)]]), 0)
})

test_that("probabilities of vertices close to the real probability", {
  g <- make_full_graph(3)
  V(g)$name <- letters[1:3]
  V(g)$likelihood <- c(1, 2, 3)
  x <-
    mcmc_sample(
      graph = g,
      module_size = 2,
      times = 1e4,
      niter = 10,
      exp_lh = 1,
      fixed_size = T
    )
  expect_lt(max(abs(get_frequency(x) / 1e4 - c(5, 8, 9) / 11)), 0.015)

  g <- graph_from_atlas(130)
  V(g)$name <- letters[1:6]
  V(g)$likelihood <- c(1, 2, 3, 1, 2, 3)
  x <-
    mcmc_sample(
      graph = g,
      module_size = 2,
      times = 1e4,
      niter = 100,
      exp_lh = 1,
      fixed_size = T
    )
  expect_lt(max(abs(
    get_frequency(x) / 1e4 - c(6, 8, 9, 6, 8, 9) / 23
  )), 0.015)

  x <-
    mcmc_sample(
      graph = g,
      module_size = 3,
      times = 1e4,
      niter = 100,
      exp_lh = 1,
      fixed_size = T
    )
  expect_lt(max(abs(
    get_frequency(x) / 1e4 - c(16, 8, 9, 16, 8, 9) / 22
  )), 0.015)

  V(g)$likelihood <- c(3, 2, 1, 3, 2, 1)
  x <-
    mcmc_sample(
      graph = g,
      module_size = 3,
      times = 1e4,
      niter = 100,
      exp_lh = 1,
      fixed_size = T
    )
  expect_lt(max(abs(
    get_frequency(x) / 1e4 - c(60, 24, 15, 60, 24, 15) / 66
  )), 0.015)
})