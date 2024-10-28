# About MyEnigmaMachine :
This project is based on the principles of enigma machine used during World War II, with some minor modifications. This project encrypts and decrypts text files rather than strings, and it will replace letters in the text file with other letters, while other characters will remain unchanged.

# How to use ?
**Environment :** 
If you are in a Windows environment, you can directly execute the exe file in the 'output folder', otherwise you will need to recompile the executable file yourself.
  
**Notice :** 
You should keep the 'rotors.txt' in the same directory as the enigma_decrypt.exe / enigma_decrypt.exe， otherwise, you will not be able to run the exe files.
    
**Encryption**
*0.Prepare* : You should create a text file and keep it in the same directory as enigma_encrypt.exe file and rotors.txt, or move text file to this directory, or move enigma_encrypt.exe and rotors.txt to destination directory. 


*1.Run* : Double click 'enigma_encrypt.exe'.(Ensure that the rotors.txt is in the same directory.)


*2.Type in the file name* : The pop-up window will display the following two lines. 
```
There are **NUMBER** rotors 
Inter file name of message :
```
Please enter the filename of the text file you want to encrypt.

If you haven't modified the rotors.txt, then the **NUMBER** will be 7, otherwise, it may be a different specified value.


*3.Type in your key* : Choose your favorite key such as "ATRNRYT". Please note that the key length should be equal to the value of **NUMBER**, and the key should consist of uppercase letters only.


*4.Finish* : When you hit enter, the window will disappear. And you will find a new file which has a same name with your text file but with .eni extension.

    
  **Decryption**
*0.Prepare* : You should keep a '.eni' file which generated in Encryption step in the same directory as enigma_decrypt.exe file and rotors.txt, or move '.eni' file to this directory, or move enigma_encrypt.exe and rotors.txt to destination directory. (You better remove the original text file from the directory to observe the runtime results.


*1.Run* : Double click 'enigma_decrypt.exe'.(Ensure that the rotors.txt is in the same directory.)


*2.Type in the file name* : The pop-up window will display the following two lines. 
```
There are **NUMBER** rotors 
Inter file name of cipher :
```
Please enter the filename of the text file you want to decrypt.

If you never modified the rotors.txt, then the **NUMBER** will be 7, otherwise, it may be a different specified value. The rotors.txt should be the one that you used when encrypting.


*3.Type in your key* : The key must be the key you chose when you encrypted the text file.


*4.Finish* : When you hit enter, the window will disappear. And you will find a new file which has a same name with your .eni file but with .txt extension.

# Difference With Enigma Machine

**It can easily change the number and kinds of rotors by a txt file.**

**Every certain number of letters, the least frequently occurring letter is inserted, although this has a limited effect on balancing the frequency of each letter's appearance.**
