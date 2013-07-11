#ifndef _KNN_H
#define _KNN_H

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/ml/ml.hpp"

#include <iostream>
#include <fstream>




using namespace cv;
using namespace std;

class KNN {
private:
	
	void min(Mat_<double>&, int&); /* minmum function to calculate minimum over a Matrix */
	void Initialize_Zero_(Mat_<double>&); /* initialize Matrix type Mat_ to zero*/
	void Compute_Centroid_(Mat_<double>&, Mat_<double>&, Mat_<int>&, Scalar&); /* Mean of points assigned to centroid */



public:
	/* enum for distances */

	enum Distance {
	
		Euclidean,
		Cosine
	};
	void Compute_Closest_(Mat_<double>& X, Mat_<double>&, Mat_<int>&, Distance); /* compute closest centroid to each example */

	void Kmeans_(Mat_<double>&, Distance, Mat_<double>&, Mat_<int>&, Scalar&); /* the k-means wrapper */
	
};


#endif