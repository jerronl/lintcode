# lintcode
solutions to lintcode

each cpp file in the subfolder under src contains solution to questions in lintcode. uncomment the lines like following:

		//*
		#pragma GCC diagnostic ignored "-Wunused-function"
		static//*/
		void test(){ // @suppress("Unused static function")
 
into 

		/*
		#pragma GCC diagnostic ignored "-Wunused-function"
		static//*/
		void test(){ // @suppress("Unused static function")
		
(by just removing the leading slash character) and build the project would run the test cases in the test function below those lines.