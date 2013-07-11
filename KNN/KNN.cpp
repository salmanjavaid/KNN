#ifndef _KNN_H
#include "KNN.hpp"
#endif

void KNN::Initialize_Zero_(Mat_<double> &X)
{
	for(int _i_ = 0; _i_ < X.rows; _i_++)
	{
		for(int _j_ = 0; _j_ < X.cols; _j_++)
		{
			X(_i_, _j_) = 0;
		}
	}
}

void KNN::min(Mat_<double>& X, int& Ind)
{
	int prev = 0, fwd = 1;
	double curr_min = X(prev, 0);
	Ind = 0;
	for(int _i_ = 0; fwd < X.rows; _i_++)
	{
		if (curr_min > X(fwd, 0))
		{
			curr_min = X(fwd, 0);
			Ind = fwd;
		}

		fwd++; prev++;
	}
}

void KNN::Compute_Closest_(Mat_<double>& X, Mat_<double>& Centroids, Mat_<int>& Indices, Distance type)
{
	Scalar _Number_Of_Centroids_ = Centroids.rows;
	Mat_<int> _Index_(X.rows, 1);
	Mat_<double> _temp_(_Number_Of_Centroids_[0], 1, CV_32F);
	Mat_<double> _Mult_temp_(1, X.cols, CV_32F);
	double _min_, _max_;
	int _minInd_;
	for (int _i_ = 0; _i_ < X.rows; _i_++)
	{
		for (int _j_ = 0; _j_ < _Number_Of_Centroids_[0]; _j_++)
		{
			multiply(X.row(_i_) - Centroids.row(_j_), X.row(_i_) - Centroids.row(_j_), _Mult_temp_);
			
			_temp_(_j_, 0) = sum(_Mult_temp_)[0];
		}

		min(_temp_, _minInd_);
		Indices(_i_, 0) = _minInd_;
		
	}

	
}

void KNN::Compute_Centroid_(Mat_<double>& X, Mat_<double>& Centroid, Mat_<int>& Index, Scalar& K)
{
	Scalar _Counter_ = 0;
	Mat_<double> _Sum_(1, X.cols);
	for (int _i_ = 0; _i_ < K[0]; _i_++)
	{
		
		Initialize_Zero_(_Sum_);
        _Counter_ = 0;
		for (int _j_ = 0; _j_ < Index.rows; _j_++)
		{
			if (Index(_j_, 0) == _i_)
			{
				add(_Sum_, X.row(_j_), _Sum_);
				_Counter_[0]++;
			}
		}

		divide(_Sum_, _Counter_[0], Centroid.row(_i_));
	
	}
}


void KNN::Kmeans_(Mat_<double>& X, Distance type, Mat_<double>& Centroid, Mat_<int>&Index, Scalar& max_iters)
{
	Scalar _Rows_ = X.rows, _Cols_ = X.cols, _K_ = Centroid.rows;
	Mat_<int> Indices(_Rows_[0], 1);
	

	for (int _i_ = 0; _i_ < max_iters[0]; _i_++)
	{
			Compute_Closest_(X, Centroid, Indices, type);
			Compute_Centroid_(X, Centroid, Indices, _K_);
	}

}