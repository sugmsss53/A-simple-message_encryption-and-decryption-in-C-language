#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int xor_encrypt(const char *msg, const char *key, char *encrypted)
{
   int msg_len = strlen(msg);
   int key_len = strlen(key);
   int i;

   for (i = 0; i < msg_len; i++)
   {
       encrypted[i] = msg[i] ^ key[i % key_len];
   }

   encrypted[i] = '\0';
   return key_len;
}

int xor_decrypt(const char *encrypted, const char *key, char *decrypted, int key_len)
{
   int encrypted_len = strlen(encrypted);
   int i;

   for (i = 0; i < encrypted_len; i++)
   {
       decrypted[i] = encrypted[i] ^ key[i % key_len];
   }

   decrypted[i] = '\0';
   return i;
}

int main()
{
   char *msg, *key1,*key2, *encrypted, *decrypted;
   int encrypted_len, decrypted_len, key_len;

   /* Get message from user */
   printf("Enter the message: ");
   msg = malloc(1024);
   fgets(msg, 1024, stdin);
   msg[strcspn(msg, "\n")] = '\0';

   /* Get key from user to encrypt*/
   printf("Enter the key to encrypt: ");
   key1 = malloc(1024);
   fgets(key1, 1024, stdin);
   key1[strcspn(key1, "\n")] = '\0';

   /* Encrypt message */
   encrypted_len = strlen(msg) + 1;
   encrypted = malloc(encrypted_len);
   key_len = xor_encrypt(msg, key1, encrypted);

   /*Print encrypted message*/
  printf("Encrypted message: %s\n", encrypted);

   /* Get key from user to decrypt*/
   printf("Enter the key to decrypt: ");
   key2 = malloc(1024);
   fgets(key2, 1024, stdin);
   key2[strcspn(key2, "\n")] = '\0';

   /* Decrypt message */
   decrypted_len = strlen(encrypted) + 1;
   decrypted = malloc(decrypted_len);
   xor_decrypt(encrypted, key2, decrypted, key_len);

   /* decrypted messages */
   
   printf("Decrypted message: %s\n", decrypted);

   free(msg);
   free(key1);
   free(encrypted);
   free(key2);
   free(decrypted);

   return 0;
}