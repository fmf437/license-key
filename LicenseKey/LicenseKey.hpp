/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project at
 * https://github.com/filipe-marques/license-key
 *
 * Please make a donation to eagle.software3@gmail.com at PayPal to
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

// lk - licensekey namespace
namespace lk
{
    class LicenseKey
	{
	public:
        LicenseKey(const std::map<std::string, std::string> &m);
		~LicenseKey();

		// show the map size
		void showSize();

        // set filename with extension: filename.bin - default: key.bin
        void setFileName(std::string filename);
		
		// write in a file a hashed key
		void writeHashKey(std::string Value);
		
		// read the hashed key from the same file
		std::string readHashKey();
		
		// compare the key with already defined map
		bool compareKey(std::string keyVal);
		
		// it reads the file ?
		bool readFile();
		
		// set file path
		void setFilePath(std::string file);
		
		// given a key, extract the value
		std::string extractValue(std::string givenKey);
		
		// given a value, compare with existing map value
		bool existValue(std::string givenValue);
		
	private:
        std::string output, read_result, filePath, fileName;
		std::map<std::string, std::string> key;
		
		//method to encrypt or decrypt
        std::string encryptDecrypt(std::string toEncryptDecrypt);
	};
}
#endif // LICENSEKEY_HPP
