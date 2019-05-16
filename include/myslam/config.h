#ifndef CONFIG_H
#define CONFIG_H

#include "myslam/common_include.h"

namespace myslam{
	class Config{
	private:
		static std::shared_ptr<Config> config_;
		cv::FileStorage file_;

		config(){} // private constructor makes a singleton
	public:
		~config(); // close the file when deconstructing

		// save a new config file
		static void setParameterFile(const std::string& filename);

		// access the parameter values
		template<typename T>
		static T get(const std::string& key){
			return T(Config::config_->file_[key]);
		}
	};

}