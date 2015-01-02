/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project
 * name of file: listcomparekeys.hpp
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

// create a list of valid keys with the size of 20 characters

#ifndef LISTCOMPAREKEYS_HPP
#define LISTCOMPAREKEYS_HPP

#include <iostream>
#include <string>
#include <vector>

namespace lk
{
	class ListCompareKeys
	{
		public:
            ListCompareKeys();
			~ListCompareKeys();
			
			// sets a new vector of keys
            int set_new_keys(std::string valid_key);
			
			// for debugging get the key and value from the vector
			void get_keys();
			
			// compare the key with already defined vector
            bool compare_key(std::string key_val);
			
		private:
			// the vector that will keep a list of valid keys
			std::vector<std::string> key;
            //int size_list;
	};
}

#endif // LISTCOMPAREKEYS_H
