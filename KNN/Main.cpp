#include "KNN.hpp"

int main(){
	CvMLData M;
	M.read_csv("J:\\Desktop\\Dump\\Machine Learning\\ex7\\Data2.csv");

	Mat_<double> X = M.get_values();

	M.read_csv("J:\\Desktop\\Dump\\Machine Learning\\ex7\\Centroids.csv");
	Mat_<double> Centroids = M.get_values();
	
	KNN K;

	Mat_<int> Index(X.rows, 1);

	Scalar max_iter = 10;
	K.Kmeans_(X, K.Euclidean, Centroids, Index, max_iter);
	return 0;
}