#pragma once
#ifndef MYSLAM_CONFIG_H
#define MYSLAM_CONFIG_H

#include "myslam/common_include.h"

namespace myslam {

/**
 * Configuration class, use SetParameter File to determine the 
 * configuration file and then use Get to get the corresponding value
 * singleton pattern
 */
class Config {
   private:
    static std::shared_ptr<Config> config_;
    cv::FileStorage file_;

    Config() {}  // private constructor makes a singleton
   public:
    ~Config();  // close the file when deconstructing

    // set a new config file
    static bool SetParameterFile(const std::string &filename);

    // access the parameter values
    template <typename T>
    static T Get(const std::string &key) {
        return T(Config::config_->file_[key]);
    }
};
}  // namespace myslam

#endif  // MYSLAM_CONFIG_H
