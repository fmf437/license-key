/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project
 * name of file: inoutkey.hpp
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

#ifndef INOUTKEY_HPP
#define INOUTKEY_HPP

#include <fstream>
#include <iostream>
#include <string>

namespace lk
{
	class InOutKey
	{
		public:
			// filename sets the of filename including the extension
            InOutKey(std::string file_name);
			
			~InOutKey();
			
			// write in a file a hashed key
			bool write_hash_key(std::string &hash_key);
			
			// read the hashed key from the same file
			std::string read_hash_key();
			
			// read_result is data from the result from read_hash_key() method
			//std::string file_name;

            // the file exists ?
            bool file_exists(std::string file_name);
			
		private:
			std::string read_result;
            std::string file;
	};
}
#endif // INOUTKEY_H
