#include "median.h"
#include <stdexcept>
#include <algorithm>
#include <numeric>

using std::sort;	using::std::domain_error;
double median(std::vector<double> vec){
	if(vec.size() == 0)
		throw domain_error("Median of empty vector.");

	sort(vec.begin(), vec.end());

	std::vector<double>::size_type vec_size = vec.size();

	std::vector<double>::size_type mid = vec.size() / 2 ;
	return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1])/2 : vec[mid];
}

double average(std::vector<double> vec){
	if(vec.size() == 0)
		throw domain_error("average of empty vector.");

	return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}