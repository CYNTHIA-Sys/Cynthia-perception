#include <eigen/Eigen/Core>


#define CY_DYNAMIC -1
#ifndef CY_EIGEN_H
#define CY_EIGEN_H

namespace cy
{
	const int Dynamic = -1;
	
	
	void func ()
	{
		Eigen::VectorXd vector( 5 );
		vector << -1 , 2 , -3 , 4 , -5;
		
		Eigen::VectorXd absVector = vector.cwiseAbs();
		vector.cast< float >();
		vector.size();
	}
	
	
	template < typename T > using Mat = Eigen::Matrix< T , Eigen::Dynamic , Eigen::Dynamic >;
	
	template < typename T > using Vec = Eigen::Vector< T , Eigen::Dynamic >;
}
#endif  // End CY_EIGEN_H