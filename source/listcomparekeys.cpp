/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project
 * name of file: listcomparekeys.cpp
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

// create a list of valid keys with the size 20 characters

#include <LicenseKey/LicenseKey/listcomparekeys.hpp>

namespace lk
{
    ListCompareKeys::ListCompareKeys()
	{

	}
	
	ListCompareKeys::~ListCompareKeys()
	{
        //key;
	}
	
    int ListCompareKeys::set_new_keys(std::string valid_key)
    {
        if(valid_key.size() < 20)
        {
            std::cout << "Error in size lenght of the string: " << valid_key <<"\n";
            return 1;
        }
        else
        {
            key.push_back(valid_key);
            return 0;
        }
	}
	
	void ListCompareKeys::get_keys()
	{
		for (std::vector<std::string>::iterator itr = key.begin(), end=key.end(); itr != end; ++itr)
		{
			std::cout << *itr << std::endl;
        }
        std::cout << "The size of the vector is: " << key.size() << std::endl;
	}
	
    bool ListCompareKeys::compare_key(std::string key_val)
	{
        for(auto &p : key)
        {
            if(p == key_val)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
	}
}
