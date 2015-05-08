/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project at
 * https://github.com/filipe-marques/license-key
 *
 * Please make a donation to eagle.software3@gmail.com at PayPal to
 * support futher development
 * 
 * name of file: LicenseKey.cpp
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

#include "LicenseKey.hpp"

// lk - licensekey namespace
namespace lk
{
	LicenseKey::LicenseKey(const std::map<std::string, std::string> &m)
	{
		key.clear();
		output.clear();
		read_result.clear();
		filePath.clear();
		fileName.clear();
		key = std::move(m);
	}

	LicenseKey::~LicenseKey()
	{
	}
	
	// show the map size
	void LicenseKey::showSize()
	{
		std::cout << key.size() << "\n";
	}
	
	// set filename with extension: filename.bin - default: key.bin
	void LicenseKey::setFileName(std::string filename)
	{
		fileName = filename;
	}
	
	// write in a file a hashed key
	void LicenseKey::writeHashKey(std::string Value)
	{
		std::ofstream file_write(filePath.data(), std::ios_base::binary);
		if(!file_write.is_open())
		{
			std::cout << "File not open - on write!" << "\n";
		}
#ifdef _WIN32
		Value = encryptDecrypt(Value);
#endif
		file_write << Value;
		file_write.flush();
		file_write.close();
	}
	
	// read the hashed key from the same file
	std::string LicenseKey::readHashKey()
	{
		std::string res;
		std::ifstream file_read(filePath.data(), std::ios_base::binary);
		if(!file_read.is_open())
		{
			std::cout << "File not open - on read!" << "\n";
		}
		while(!file_read.eof())
		{
			file_read >> res;
			read_result += res;
			res.clear();
		}
#ifdef _WIN32
		read_result = encryptDecrypt(read_result);
#endif
		file_read.close();
		return read_result;
	}
	
	// compare the key with already defined map
	bool LicenseKey::compareKey(std::string keyVal)
	{
		for(auto &p : key)
			if(p.first == keyVal)
				return true;
		return false;
	}
	
	// it reads the file ?
	bool LicenseKey::readFile()
	{
		std::ifstream file_read(filePath.data(), std::ios_base::binary);
		if(!file_read.is_open())
		{
			file_read.close();
			return false;
		}
		file_read.close();
		return true;
	}
	
	// set file path
	void LicenseKey::setFilePath(std::string file)
	{
		filePath = file;
		if(fileName.empty())
			filePath.append("key.bin");
		else
			filePath.append(fileName);
		//std::cout << filePath << "\n";
	}
	
	// given a key, extract the value
	std::string LicenseKey::extractValue(std::string givenKey)
	{
		std::string result;
		for(auto &gk : key)
			if(gk.first == givenKey)
				result = gk.second;
		return result;
	}
	
	// given a value, compare with existing map value
	bool LicenseKey::existValue(std::string givenValue)
	{
		for(auto &gv : key)
			if(gv.second == givenValue)
				return true;
		return false;
	}
	
#ifdef _WIN32
	//method to encrypt or decrypt
	std::string LicenseKey::encryptDecrypt(std::string toEncryptDecrypt)
	{
		//Any chars will work, in an array of any size
		char keyDEncrypt[12] = {'1','3','5','7','9','3','2','4','6','8','A','b'};
		output = toEncryptDecrypt;
		for (unsigned int i = 0; i < toEncryptDecrypt.size(); i++)
			output[i] = toEncryptDecrypt[i] ^ keyDEncrypt[i % (sizeof(keyDEncrypt) / sizeof(char))];
		return output;
	}
#endif
}
