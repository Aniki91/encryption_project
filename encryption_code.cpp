#include<iostream>

using namespace std;

int main()
{
	char letter[29] = {'*','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','%'};
	
	// NOTE: All elements are set to +1 above what is required
	// due to an error post exiting the programing about memory.

	char origPlain[9];
	char plain[9];
	char plain1[5];
	char plain2[5];
	char part1[5];
	char part2[5];
	char enc_plain1[5];
	char enc_plain2[5];
	int cipher[5];
	int cipher1[5];
	int cipher2[5];
	int strProductMOD1[5];
	int strProductMOD2[5];
	int enc_elements1[5];
	int enc_elements2[5];

	int menu_select = 0;

	int n = 29;

	// Used for several incrementing loops.
	int i = 0;
	int j = 0;
	int k = 0;
	int p = 0;
	int c = 0;
	int multiply = 0;

	// Product of Matrices output Matrix.
	float product[10][10];

	// int arrays for the D*E = I(mod n) output.
	int Row1[4];
	int Row2[4];
	int Row3[4];
	int Row4[4];
	
	// Encryption Matrix values.
	float E[4][4] = 
	{
		{ 9, 12, 23, 1 },
		{ 24, 5, 24, 19 },
		{ 13 , 2, 21, 13 },
		{ 1, 3, 25, 15 }
	};

	// Decryption Matrix values.
	float D[4][4] = 
	{
		{ 10, 12, 8, 12 },
		{ 6, 21, 23, 13 },
		{ 20, 11, 19, 5 },
		{ 17, 25, 27, 27 }
	};

	// Empty Matrix for the output from D*E calculation.
	float C[4][4] =
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	};
	
	// Used to clear the screen through the program.
	system("CLS");

	// Find the corresponding index to letters.
	cout << "Input a word with 4 letters: \n" << endl;
	cin >> plain;

	system("CLS");

	// Input the 4 letter word into a new array that won't be modified through the program.
	for(i = 0; i < 8; i++)
	{
		origPlain[i] = plain[i];
	}

	i = 0; // Resetting the value of i.


	// Inputting the first 4 elements into part1.
	for(i = 0; i < 4; i++)
	{
		part1[i] = plain[i];
	}

	// Inputting the last 4 elements into part2.
	for(i = 4; i < 8; i++)
	{
		part2[i - 4] = plain[i];
	}
	
	// Resetting i for use within the element number algorithm.
	i = 0;

	// Algorithm to output the element number locations through the letter array into cipher1 from part1.
	while(p < 4)
	{
		if(letter[i] == part1[p])
		{
			cipher1[p] = i;

			p++;

			i = 0;
		}
		else
		{
			i++;
		}
	}

	p = 0;

	// Algorithm to output the element number locations through the letter array into cipher2 from part2.
	while(p < 4)
	{
		if(letter[i] == part2[p])
		{
			cipher2[p] = i;

			p++;

			i = 0;
		}
		else
		{
			i++;
		}
	}

	// Multiply the Matrices ready for modulus for cipher1.
    for(i = 0; i < 4; i++)
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 1; j++)
			{
				multiply = 0;

				for(k = 0; k < 4; k++)
				{
					multiply = multiply + E[i][k] * cipher1[k];
				}
				product[i][j] = multiply;
			}
		}
	}

	// Assigning the elements of the matrix to an int array strProductMOD1.
	for(i = 0; i < 4; i ++)
	{
		strProductMOD1[i] = product[i][0];
	}

	// (mod n) each value in the array.
	for(i = 0; i < 4; i++)
	{
		strProductMOD1[i] = strProductMOD1[i] % n;
	}

	// Algorithm to output the letters from letter array into enc_plain1 for the menu call.
	while(c < 4)
	{
		if(i == strProductMOD1[c])
		{
			enc_plain1[c] = letter[i];

			c++;
			i=0;
		}
		else
		{
			i++;
		}
	}

	for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 1; j++)
        {
            enc_elements1[i] = strProductMOD1[i];
        }
    }

	// Multiply the Matrices ready for modulus for cipher2.
    for(i = 0; i < 4; i++)
	{		
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 1; j++)
			{
				multiply = 0;

				for(k = 0; k < 4; k++)
				{
					multiply = multiply + E[i][k] * cipher2[k];
				}
				product[i][j] = multiply;
			}
		}
	}

	// Assigning the elements of the matrix to an int array strProductMOD2.
	for(i = 0; i < 4; i ++)
	{
		strProductMOD2[i] = product[i][0];
	}

	// (mod n) each value in the array.
	for(i = 0; i < 4; i++)
	{
		strProductMOD2[i] = strProductMOD2[i] % n;
	}

	// resetting c.
	c = 0;

	// Algorithm to output the letters from letter array into enc_plain2 for the menu call.
	while(c < 4)
	{
		if(i == strProductMOD2[c])
		{
			enc_plain2[c] = letter[i];

			c++;
			i=0;
		}
		else
		{
			i++;
		}
	}

	// Assign the elements from strProductMOD2[i] into enc_elements2[i] for the menu call.
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 1; j++)
        {
            enc_elements2[i] = strProductMOD2[i];
        }
    }

	// Multiply the Matrices to decrypt for strProductMOD1.
    for(i = 0; i < 4; i++)
	{
        for(j = 0; j < 1; j++)
		{
            product[i][j] = 0;
		}
			
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 1; j++)
			{
				multiply = 0;

				for(k = 0; k < 4; k++)
				{
					multiply = multiply + D[i][k] * strProductMOD1[k];
				}
				product[i][j] = multiply;
			}
		}
	}

	// Assigning the elements of the matrix to an int array strProductMOD1.
	for(i = 0; i < 4; i ++)
	{
		strProductMOD1[i] = product[i][0];
	}

	// (mod n) each value in the array.
	for(i = 0; i < 4; i++)
	{
		strProductMOD1[i] = strProductMOD1[i] % n;
	}

	// Resetting variable 'c' for use with the next while() loop.
	c = 0;

	// Algorithm to output the letters from letter array into plain1 for the menu call.
	while(c < 4)
	{
		if(i == strProductMOD1[c])
		{
			plain1[c] = letter[i];

			c++;
			i=0;
		}
		else
		{
			i++;
		}
	}

	// Multiply the Matrices to decrypt.
    for(i = 0; i < 4; i++)
	{
        for(j = 0; j < 1; j++)
		{
            product[i][j] = 0;
		}
			
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 1; j++)
			{
				multiply = 0;

				for(k = 0; k < 4; k++)
				{
					multiply = multiply + D[i][k] * strProductMOD2[k];
				}
				product[i][j] = multiply;
			}
		}
	}

	// Assigning the elements of the matrix to an int array strProductMOD2
	for(i = 0; i < 4; i ++)
	{
		strProductMOD2[i] = product[i][0];
	}

	// (mod n) each value in the array.
	for(i = 0; i < 4; i++)
	{
		strProductMOD2[i] = strProductMOD2[i] % n;
	}

	// Resetting variable 'c' for use with the next while() loop.
	c = 0;

	// Algorithm to output the letters from letter array into plain2 for the menu call.
	while(c < 4)
	{
		if(i == strProductMOD2[c])
		{
			plain2[c] = letter[i];

			c++;
			i=0;
		}
		else
		{
			i++;
		}
	}

	// Multiply the Decrypt Matrix and the Encrypt Matrix.
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			for(k = 0; k < 4; k++)
			{
				C[i][j] += D[i][k] * E[k][j];
			}
		}
	}

	// Apply each row of the D*E matrix to char arrays and (mod n) each element for output.
	for(i = 0; i < 4; i++)
	{
		Row1[i] = C[i][0];
		Row1[i] = Row1[i] % n;

		Row2[i] = C[i][1];
		Row2[i] = Row2[i] % n;

		Row3[i] = C[i][2];
		Row3[i] = Row3[i] % n;

		Row4[i] = C[i][3];
		Row4[i] = Row4[i] % n;
	}

	// Menu start.
Menu_Start:

	cout << "Main Menu: \n" << endl;
	cout << "===========\n" << endl;
	cout << "1. View the original word - (Assignment requirement).\n\n";
	cout << "2. View the original word's letter element numbers.\n\n";
	cout << "3. View the encrypted word's letter element numbers.\n\n";
	cout << "4. Display the word after the encryption process - (Assignment requirement).\n\n";
	cout << "5. Display the word after the decryption process - (Assignment requirement).\n\n";
	cout << "6. Display matrix found from D*E = I(mod n) calculation.\n\n";
	cout << "7. Exit the program.\n";
	cin >> menu_select;
	
	// View the original word.
	if(menu_select == 1)
	{
		system("CLS");
		cout << "The original word is: ";

		for(i = 0; i < 8; i++)
		{
			cout << origPlain[i];
		}

		cout << "\n" << endl;
		menu_select = 0;

		goto Menu_Start;
	}
	
	// View the original word's letter element numbers.
	if(menu_select == 2)
	{
		system("CLS");
		cout << "The original word's letter element numbers are: ";

		for(i = 0; i < 4; i++)
		{
			cout << " " << cipher1[i];
		}

		for(i = 0; i < 4; i++)
		{
			cout << " " << cipher2[i];
		}

		cout << "\n" << endl;
		menu_select = 0;

		goto Menu_Start;
	}

	// View the encrypted word's letter element numbers.
	if(menu_select == 3)
	{
		system("CLS");
		cout << "The encrypted word's letter element numbers are: ";

		for(i = 0; i < 4; i++)
		{
			cout << " " << enc_elements1[i];
		}

		for(i = 0; i < 4; i++)
		{
			cout << " " << enc_elements2[i];
		}

		cout << "\n" << endl;
		menu_select = 0;

		goto Menu_Start;
	}

	// Display the word after the encryption process.
	if(menu_select == 4)
	{
		system("CLS");
		cout << "The encrypted word is: ";

		for(i = 0; i < 4; i++)
		{
			cout << enc_plain1[i];
		}

		for(i = 0; i < 4; i++)
		{
			cout << enc_plain2[i];
		}
		cout << "\n" << endl;
		menu_select = 0;

		goto Menu_Start;
	}

	// Display the word after the decryption process.
	if(menu_select == 5)
	{
		system("CLS");
		cout << "The dencrypted word is: ";

		for(i = 0; i < 4; i++)
		{
			cout << plain1[i];
		}

		for(i = 0; i < 4; i++)
		{
			cout << plain2[i];
		}
		cout << "\n" << endl;
		menu_select = 0;

		goto Menu_Start;
	}

	// Display matrix found from D*E = I(mod n) calculation.
	if(menu_select == 6)
	{
		system("CLS");
		cout << "D*E = I(mod n): " << endl;
		for(i = 0; i < 4; i++)
		{
			cout << "\t" << Row1[i];
			cout << "\t" << Row2[i];
			cout << "\t" << Row3[i];
			cout << "\t" << Row4[i] << endl;
		}
		cout << "\n" << endl;
		menu_select = 0;

		goto Menu_Start;
	}

	// Exit the program.
	if(menu_select == 7)
	{
		return 0;
	}
}