/*
 * LicenseKey is a library to help you protect your program with key hashs strings
 * This file is part of LicenseKey library project
 * name of file: hashkey.cpp
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

#include <LicenseKey/LicenseKey/hashkey.hpp>

// lk - license key
namespace lk 
{
    HashKey::HashKey()
	{
	}
	
	HashKey::~HashKey()
	{
	}
	
    std::string HashKey::encryptDecrypt(std::string &toEncrypt) // , std::vector<char> &key_de_encrypt
	{	
		//Any chars will work, in an array of any size
		// AUtoDowN1946
        /*
        char key_de_encrypt[12] = {'A', 'U', 't', 'o', 'D', 'o', 'w', 'N', '1', '9', '4', '6'};
		
		output = toEncrypt;
		for (unsigned int i = 0; i < toEncrypt.size(); i++)
			output[i] = toEncrypt[i] ^ key_de_encrypt[i % (sizeof(key_de_encrypt) / sizeof(char))];
		return output;
        */

        int count{}, lenght{};
        lenght = toEncrypt.size();
        for(count = 0; count < lenght; count++)
        {
            if(isalpha(toEncrypt[count]))
            {
                toEncrypt[count] = tolower(toEncrypt[count]);
                for(int i = 0; i < 13; i++)
                {
                    if (toEncrypt[count] == 'z')
                        toEncrypt[count] = 'a';
                    else
                        toEncrypt[count]++;
                }
            }
        }
        output = toEncrypt;
        return output;
    }
}
