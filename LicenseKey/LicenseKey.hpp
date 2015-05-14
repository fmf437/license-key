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
 * \n 1 - Every time a program is executed, in main.cpp using the code of the library licensekey, it checked if the key already exists in the path of the key.bin and if the key its valid by comparing it with values in the code.
 * \n 1.1 - If not exist the key in the file, do not execute the program, instead shows the interface for the user, after purchase the key, to insert it in the key.bin and validate the program and then the user can use the program.
 * \n 2 - If exists the key in the file, it execute the program.
 * \n
 * \n So, for the comparisons of the map and to set the passphrase to encrypt or decrypt, you need to create a header file, called SetVars.hpp:
 * \n Note, that you edit directly this file, there is no get and set member functions to insert, delete or update the data !
 * \n 
 * \code{.cpp}
 *  #ifndef SETVARS_HPP
 *  #define SETVARS_HPP
 * 
 *  struct SetVars
 *  {
 *    // this is just an example - put any keys and values you want
 *    const std::map<std::string, std::string> amap{
 *        {"KEY_HERE","VALUE_HERE"},
 *     };
 *    
 *    // this is just an example
 *    const std::string passphrase{"0123456789aB"};
 *  };
 * 
 *  #endif // SETVARS_HPP
 * \endcode
 * \n Then you can include this header where you use the library LicenseKey:
 * \n
 * \code{.cpp}
 *  #include "SetVars.hpp"
 *  #include "LicenseKey.hpp"
 *
 *  // LicenseKey namespace: lk
 *  using namespace lk;
 *
 *  // ...
 *
 *  // using library LicenseKey
 *  SetVars sv;
 *  LicenseKey lek{sv.amap};
 *
 *  // ...
 *
 *  lek.readHashKey(sv.passphrase);
 *  lek.writeHashKey(someValue, sv.passphrase);
 *
 *  lek.setFilePath("afolder/inside_folder/");
 * \endcode
 * \n You have to create the folder path (create the folders) for the file be created,
 *    since yet the library doesn't support the creation of folders !
 * \n
 * \n How do I use this library ? Let's go to a tutorial !
 * \n Imagine you have a hello world program and your program just displays
 * the message "hello world" to users who had registed the program (purchasing a valid key).
 * \n So in the main.cpp file:
 * \code{.cpp}
 *  // ...
 *  #include "inc/SetVars.hpp"
 *  #include "inc/InsertKey.hpp"
 *  #include "LicenseKey.hpp"
 *  int main(int argc, char *argv[])
 *  {
 *      bool re = false;
 *      std::string pp, insert_key;
 *      SetVars sv;
 *      lk::LicenseKey lic{sv.amap};
 *      // you could know what is the size of the map
 *      // lic.showSize();
 *      lic.setFilePath("folder/inside_folder/");
 *      if(lic.readFile())
 *      {
 *          pp = lic.readHashKey(sv.passphrase);
 *          if(lic.existValue(pp))
 *              re = true;
 *      }
 *      if(re)
 *          std::cout << "Hello World !" << std::endl;
 *      else
 *      {
 *          std::cout << "Please purchase a valid key in this <a href=\"www.somelinktobuy.com\">link</a>" << std::endl;
 *          // write a class to insert the key
 *          InsertKey ik;
 *          std::cout << "Insert a valid key: " << std::endl;
 *          cin >> insert_key;
 *          ik.insert(insert_key);
 *      }
 *      return 0;
 *  }
 * \endcode
 * \n In InsertKey.cpp source file:
 * \code{.cpp}
 *  //...
 *  #include "inc/SetVars.hpp"
 *  #include "inc/InsertKey.hpp"
 *  #include "LicenseKey.hpp"
 *
 *  void insert(std::string in)
 *  {
 *      SetVars sv;
 *      lk::LicenseKey list{sv.amap};
 *      list.setFilePath("folder/inside_folder/");
 *      std::string fk;
 *      if(list.compareKey(in))
 *      {
 *          fk = list.extractValue(in);
 *          list.writeHashKey(fk, sv.passphrase);
 *          std::cout << "Validated sucessfully ! Congratulations you validated sucessfully the program !"
 *                      << "Thank you for buying, it will fund futher development !"
 *                      << "Please restart your program by clicking it again." << std::endl;
 *      }
 *  }
 *  //...
 * \endcode
 */

namespace lk
{

/*! 
 *  \brief     class LicenseKey
 *  \details   This library helps the developer implementing the key system in his program.
 *  \author    Filipe Marques
 *  \version   2.0.0
 *  \copyright &copy; 2014 2015 Filipe Marques GNU General Public License version 3
 */

    class LicenseKey
	{
	public:

        //! constructor
        /*!
          @param m is a map constant reference
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
          @param filename is the name of file with extension
        */
		void setFileName(std::string filename);
		
        //-------------------------------------------------------------------------------------
        //! write in a file a hashed key
        /*!
          @param Value is a std::string variable
          @param passPhrase is a constant std::string variable
        */
        void writeHashKey(std::string Value, const std::string passPhrase);

        //-------------------------------------------------------------------------------------
        //! read the hashed key from the same file
        /*!
          @param passPhrase is a constant std::string variable
          @return the key from file defined previously
        */
        std::string readHashKey(const std::string passPhrase);

        //-------------------------------------------------------------------------------------
        //! compare the key with already defined map
        /*!
          @param keyVal is a std::string variable, that is the key of a map
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
          @param file is a std::string variable
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

        // member function to encrypt or decrypt
        std::string encryptDecrypt(std::string toEncryptDecrypt, const std::string passPhrase);
	};
}

#endif // LICENSEKEY_HPP
