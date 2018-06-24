// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// mcmc_subgraph_internal
LogicalVector mcmc_subgraph_internal(IntegerMatrix edgelist, List args);
RcppExport SEXP _mcmcRanking_mcmc_subgraph_internal(SEXP edgelistSEXP, SEXP argsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< List >::type args(argsSEXP);
    rcpp_result_gen = Rcpp::wrap(mcmc_subgraph_internal(edgelist, args));
    return rcpp_result_gen;
END_RCPP
}
// sample_llh_internal
NumericVector sample_llh_internal(IntegerMatrix edgelist, NumericVector likelihood, List args, LogicalMatrix start_module);
RcppExport SEXP _mcmcRanking_sample_llh_internal(SEXP edgelistSEXP, SEXP likelihoodSEXP, SEXP argsSEXP, SEXP start_moduleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type likelihood(likelihoodSEXP);
    Rcpp::traits::input_parameter< List >::type args(argsSEXP);
    Rcpp::traits::input_parameter< LogicalMatrix >::type start_module(start_moduleSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_llh_internal(edgelist, likelihood, args, start_module));
    return rcpp_result_gen;
END_RCPP
}
// mcmc_sample_internal
LogicalVector mcmc_sample_internal(IntegerMatrix edgelist, NumericVector likelihood, List args, LogicalMatrix start_module);
RcppExport SEXP _mcmcRanking_mcmc_sample_internal(SEXP edgelistSEXP, SEXP likelihoodSEXP, SEXP argsSEXP, SEXP start_moduleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type likelihood(likelihoodSEXP);
    Rcpp::traits::input_parameter< List >::type args(argsSEXP);
    Rcpp::traits::input_parameter< LogicalMatrix >::type start_module(start_moduleSEXP);
    rcpp_result_gen = Rcpp::wrap(mcmc_sample_internal(edgelist, likelihood, args, start_module));
    return rcpp_result_gen;
END_RCPP
}
// probabilistic_rank_internal
IntegerVector probabilistic_rank_internal(IntegerMatrix edgelist, DataFrame df_nodes);
RcppExport SEXP _mcmcRanking_probabilistic_rank_internal(SEXP edgelistSEXP, SEXP df_nodesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type df_nodes(df_nodesSEXP);
    rcpp_result_gen = Rcpp::wrap(probabilistic_rank_internal(edgelist, df_nodes));
    return rcpp_result_gen;
END_RCPP
}
// mcmc_onelong_internal
IntegerVector mcmc_onelong_internal(IntegerMatrix edgelist, NumericVector likelihood, List args);
RcppExport SEXP _mcmcRanking_mcmc_onelong_internal(SEXP edgelistSEXP, SEXP likelihoodSEXP, SEXP argsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type likelihood(likelihoodSEXP);
    Rcpp::traits::input_parameter< List >::type args(argsSEXP);
    rcpp_result_gen = Rcpp::wrap(mcmc_onelong_internal(edgelist, likelihood, args));
    return rcpp_result_gen;
END_RCPP
}
// mcmc_onelong_frequency_internal
IntegerVector mcmc_onelong_frequency_internal(IntegerMatrix edgelist, NumericVector likelihood, List args);
RcppExport SEXP _mcmcRanking_mcmc_onelong_frequency_internal(SEXP edgelistSEXP, SEXP likelihoodSEXP, SEXP argsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type likelihood(likelihoodSEXP);
    Rcpp::traits::input_parameter< List >::type args(argsSEXP);
    rcpp_result_gen = Rcpp::wrap(mcmc_onelong_frequency_internal(edgelist, likelihood, args));
    return rcpp_result_gen;
END_RCPP
}
// real_prob_internal
NumericVector real_prob_internal(IntegerMatrix edgelist, NumericVector likelihood);
RcppExport SEXP _mcmcRanking_real_prob_internal(SEXP edgelistSEXP, SEXP likelihoodSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type edgelist(edgelistSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type likelihood(likelihoodSEXP);
    rcpp_result_gen = Rcpp::wrap(real_prob_internal(edgelist, likelihood));
    return rcpp_result_gen;
END_RCPP
}
// accurate_sum
NumericVector accurate_sum(NumericVector v);
RcppExport SEXP _mcmcRanking_accurate_sum(SEXP vSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type v(vSEXP);
    rcpp_result_gen = Rcpp::wrap(accurate_sum(v));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_mcmcRanking_mcmc_subgraph_internal", (DL_FUNC) &_mcmcRanking_mcmc_subgraph_internal, 2},
    {"_mcmcRanking_sample_llh_internal", (DL_FUNC) &_mcmcRanking_sample_llh_internal, 4},
    {"_mcmcRanking_mcmc_sample_internal", (DL_FUNC) &_mcmcRanking_mcmc_sample_internal, 4},
    {"_mcmcRanking_probabilistic_rank_internal", (DL_FUNC) &_mcmcRanking_probabilistic_rank_internal, 2},
    {"_mcmcRanking_mcmc_onelong_internal", (DL_FUNC) &_mcmcRanking_mcmc_onelong_internal, 3},
    {"_mcmcRanking_mcmc_onelong_frequency_internal", (DL_FUNC) &_mcmcRanking_mcmc_onelong_frequency_internal, 3},
    {"_mcmcRanking_real_prob_internal", (DL_FUNC) &_mcmcRanking_real_prob_internal, 2},
    {"_mcmcRanking_accurate_sum", (DL_FUNC) &_mcmcRanking_accurate_sum, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_mcmcRanking(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
