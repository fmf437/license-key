/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project
 * name of file: hashkey.hpp
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

// encript and decript a selected valid key and returns the result

#ifndef HASHKEY_HPP
#define HASHKEY_HPP

#include <string>
#include <vector>

namespace lk
{
	class HashKey
	{
		public:
			HashKey();
			~HashKey();
			
            // to encrypt or decrypt
            std::string encryptDecrypt(std::string &toEncrypt);

		private:
			// the output result
            std::string output;
	};
}

#endif // HASHKEY_H

