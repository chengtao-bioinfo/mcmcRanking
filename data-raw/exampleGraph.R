library(BioNet)
library(DLBCL)
library(genefilter)
library(impute)
library(igraph)
library(mcmcRanking)

data(exprLym)
expressions <- impute.knn(exprs(exprLym))$data
t.test <- rowttests(expressions, fac = exprLym$Subgroup)
ttest.pval <- t.test[, "p.value"]
names(ttest.pval) <- rownames(expressions)

data(interactome)
network <- subNetwork(featureNames(exprLym), interactome)
network <- largestComp(network)

exampleGraph <- simplify(graph_from_graphnel(network))
V(exampleGraph)$pval <- ttest.pval[V(exampleGraph)$name]
exampleGraph <- set_likelihood(graph = exampleGraph, fdr = 1e-7)

depth <- repetition_depth(max(V(exampleGraph)$likelihood)
                          / min(V(exampleGraph)$likelihood))

times <- 1e3
z <-
  mcmc_sample(
    graph = exampleGraph,
    subgraph_order = 1,
    times = times,
    niter = 2e4,
    exp_lh = 1 / 2 ^ (depth:0)
  )

q <- (times - get_frequency(z)) / times
V(exampleGraph)$q <- q[V(exampleGraph)$name]

r <- probabilistic_rank(graph = exampleGraph, q = q)
V(exampleGraph)$r <- r[V(exampleGraph)$name]

devtools::use_data(exampleGraph, overwrite = TRUE, compress = "xz")
