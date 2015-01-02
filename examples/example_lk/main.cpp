/*
 * example_lk is a example program for teaching the use of License Key project
 * This file is part of example_lk
 * name of file: main.cpp
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

#include <iostream>
#include <string>

#include "licensekey.hpp"

using namespace std;

int main()
{
    lk::ListCompareKeys lck;

    // keys in lower case
    // note that numbers are not hashed
    string name {"filipemarques1234567"}, name2 {"helloworld!123456789"};

    // put a list of keys - one key 20 caracters each
    lck.set_new_keys(name);
    lck.set_new_keys(name2);

    // just for debugging
    lck.get_keys();

    cout << "name: " << name << "\n";

// Uncomment or Comment this block of code to test-------------------------------------------------------------
// Encrypt the string license key and insert the hashed binary string in to the file
    lk::HashKey hk;
    string result = hk.encryptDecrypt(name);

    cout << "result: " << result << "\n";

    lk::InOutKey inout("text.bin"); // text.txt - for testing and debugging
    if (inout.write_hash_key(result))
    {
        cout << "Sucess write to file! " << "\n";
    }
//-------------------------------------------------------------------------------------------------------------


// Retrieve the hashed string license key from the file and compare it with vector of license key
// Uncomment or Comment this block of code to test-------------------------------------------------------------
   // lk::InOutKey inout("text.bin"); // text.txt - for testing and debugging
   // lk::HashKey hk;
//-------------------------------------------------------------------------------------------------------------

    if(inout.file_exists("text.bin"))
        cout << "File exists!\n";
    else
    {
        cout << "File don't exist!\n";
        return 1;
    }

    string resu = inout.read_hash_key();

    cout << "resu: " << resu << "\n";

    string res = hk.encryptDecrypt(resu);

    resu.clear();

    cout << "res: " << res << "\n";

    if (!lck.compare_key(res))
    {
        cout << "Please buy a valid license key in http://www.yoursite.com/ !!!\n";
        return 1;
    }
    else
        cout << "Valid key license found, thank you for buying this software !!!\n";
   return 0;
}

