#ifndef DES_CRYPT_H
#define DES_CRYPT_H

void HexToBinary(int Hex[], int Binary[]);
void BinaryToHex(int Binary[], int Hex[]);
int  IntPow(int x, int n);
void GetSubkey(int key[], int Subkey[][48]);
void LeftMove(int x[], int y[], int n);
void Replace(int C[], int D[], int key[]);
void Combine(int C[], int D[], int key[]);
void Encrypt(int Plaintext[], int Subkey[][48], int Ciphertext[]);
void ReplaceIP(int Plaintext[], int L[], int R[]);
void ArrayCopy(int x[], int y[]);
void EncryptCore(int output[], int L[], int R[], int K[]);
void InverseReplaceIP(int output[], int L[], int R[]);
void ESelect(int output[], int x[]);
void Sbox(int x[], int y[]);
void Reorder(int x[], int output[]);
void Decrypt(int Ciphertext[], int Subkey[][48], int DePlaintext[]);
void Display(int x[], int n);
void DecToBinary(int x[], int n);

#endif