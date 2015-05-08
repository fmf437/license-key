/*
 * LicenseKey is a library to help you protect your program with key to sell it !
 * This file is part of LicenseKey library project at
 * https://github.com/filipe-marques/license-key
 *
 * Please make a donation to eagle(dot)software3(at)gmail(dot)com at PayPal to
 * support futher development
 * 
 * name of file: LicenseKey.hpp
 *
 * Copyright (C) 2014 2015 Filipe Marques <eagle.software3@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LICENSEKEY_HPP
#define LICENSEKEY_HPP

#include <map>
#include <fstream>
#include <string>
#include <iostream>

//! \namespace lk
//! \class LicenseKey
/**
 * \verbatim "When we speak of free software, we are referring to freedom, not price."\endverbatim  in <a href="http://www.gnu.org/licenses/gpl-3.0.html">GNU GPL v.3 </a>
 * \n
 * \n LicenseKey makes the protection of a program with keys easy and that way your program can be selled
 * to others.
 * \n Your project must licensed under GNU GPL v.3.
 * \n Please consider doing a donation at PayPal to eagle(dot)software3(at)gmail(dot)com to support futher development.
 * \n
 * \n Using this library takes 2 steps:
 * \n 1 - Every time a program is executed, in main.cpp using the code of the library licensekey, it checked if the key already exists in the path of the file.bin and if the key its valid by comparing it with values in the code.
 * \n 1.1 - If not exist the key in the file, do not execute the program, instead shows the interface for the user, after purchase the key, to insert it in the file.bin and validate the program and then the user can use the program.
 * \n 2 - If exists the key in the file, it execute the program.
 * \n
 * \n So, for the comparisons of the map, you need to create a header file, called SetMap.hpp:
 * \n 
 * \code{.cpp}
 *  #ifndef SETMAP_HPP
 *  #define SETMAP_HPP
 * 
 *  struct SetMap
 *  {
 *    const std::map<std::string, std::string> mm{
 *        {"KEY_HERE","VALUE_HERE"},
 *     };
 *  };
 * 
 *  #endif // SETMAP_HPP
 * \endcode
 * \n Then you can include it where you use the library LicenseKey.
 */
namespace lk
{
/*! 
 *  \brief     class LicenseKey
 *  \details   This class helps the developer implementing the key system in their program.
 *  \author    Filipe Marques
 *  \version   2.0.0
 *  \copyright &copy; 2014 2015 Filipe Marques GNU General Public License version 3
 */
	class LicenseKey
	{
	public:
        //! constructor
        /*!
          @param m is a constant map reference
        */
		LicenseKey(const std::map<std::string, std::string> &m);
        //! destructor
        ~LicenseKey();

        //-------------------------------------------------------------------------------------
        //! show the LicenseKey map size
        /*!
          show the map size in a number
        */
		void showSize();

        //-------------------------------------------------------------------------------------
        //! set filename with extension example: filename.bin - the default is: key.bin
        /*!
          @param filename - name of filename with extension
        */
		void setFileName(std::string filename);
		
        //-------------------------------------------------------------------------------------
        //! write in a file a hashed key
        /*!
          @param Value - is a std::string variable
        */
        void writeHashKey(std::string Value);

        //-------------------------------------------------------------------------------------
        //! read the hashed key from the same file
        /*!
          @return the key from file defined previously
        */
        std::string readHashKey();

        //-------------------------------------------------------------------------------------
        //! compare the key with already defined map
        /*!
          @param keyVal - keyVal is a std::string variable, that is the key of a map
          @return true if exists, otherwise false
        */
        bool compareKey(std::string keyVal);

        //-------------------------------------------------------------------------------------
        //! checks if it read the file
        /*!
          @return true if reads the file, otherwise false
        */
        bool readFile();

        //-------------------------------------------------------------------------------------
        //! set file path with slashes
        /*!
          @param file - is a std::string variable
        */
        void setFilePath(std::string file);

        //-------------------------------------------------------------------------------------
        //! given a key, extract the value
        /*!
          @param givenKey is a std::string variable
          @return the corresponding value for the key
        */
        std::string extractValue(std::string givenKey);

        //-------------------------------------------------------------------------------------
        //! given a value, compare with existing map value
        /*!
          @param givenValue is a std::string variable
          @return true if exists, otherwise false
        */
        bool existValue(std::string givenValue);
		
	private:
		std::string output, read_result, filePath, fileName;
        std::map<std::string, std::string> key;

#ifdef __linux__
        //std::string encryptDecrypt(std::string toEncryptDecrypt); with botan or cryptopp
#endif
		
#ifdef _WIN32
		//method to encrypt or decrypt
        std::string encryptDecrypt(std::string toEncryptDecrypt);
#endif
	};
}
#endif // LICENSEKEY_HPP
