/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project
 * name of file: inoutkey.cpp
 * Copyright (C) 2014 2015 Filipe Marques eagle.software3@gmail.com
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

// insert or read the encripted result in a binary file .bin

#include <LicenseKey/LicenseKey/inoutkey.hpp>

namespace lk
{
    InOutKey::InOutKey(std::string file_name) : file{file_name}
	{
		
	}
	
	InOutKey::~InOutKey()
	{
		
	}
	
	// usar exceptions
	
	// write in a file a hashed key
	bool InOutKey::write_hash_key(std::string &hash_key)
	{
        std::ofstream file_write(file.c_str(), std::ios_base::binary);
		if(!file_write.is_open())
		{
            std::cerr << "Class InOutKey - method write_hash_key say: FILE NOT OPEN!!!" << "\n";
		}
        file_write << hash_key;
		file_write.flush();
		file_write.close();
		return true;
	}
	
	std::string InOutKey::read_hash_key()
	{
        std::ifstream file_read(file.c_str(), std::ios_base::binary);
		if(!file_read.is_open())
		{
            std::cerr << "Class InOutKey - method read_hash_key say: FILE NOT OPEN!!!" << "\n";
		}

        std::string res;

        while(!file_read.eof())
        {
            file_read >> res;

            read_result += res;
            //if(file_read.eof())
            //{
                //break;
            //}
        }
		file_read.close();
        return read_result;
    }

    bool InOutKey::file_exists(std::string file_name)
    {
        std::ifstream fil_read(file_name.c_str(), std::ios_base::binary);
        if(!fil_read.is_open())
        {
            fil_read.close();
            return false;
        }
        fil_read.close();
        return true;
    }
}
