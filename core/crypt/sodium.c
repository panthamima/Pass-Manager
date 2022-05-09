// // #include <stdio.h>
// // #include <sodium.h>

// // #define CHUNK_SIZE 4096

// // static int
// // encrypt(const char *target_file, const char *source_file,
// //         const unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES])
// // {
// //     unsigned char  buf_in[CHUNK_SIZE];
// //     unsigned char  buf_out[CHUNK_SIZE + crypto_secretstream_xchacha20poly1305_ABYTES];
// //     unsigned char  header[crypto_secretstream_xchacha20poly1305_HEADERBYTES];
// //     crypto_secretstream_xchacha20poly1305_state st;
// //     FILE          *fp_t, *fp_s;
// //     unsigned long long out_len;
// //     size_t         rlen;
// //     int            eof;
// //     unsigned char  tag;

// //     fp_s = fopen(source_file, "rb");
// //     fp_t = fopen(target_file, "wb");
// //     crypto_secretstream_xchacha20poly1305_init_push(&st, header, key);
// //     fwrite(header, 1, sizeof header, fp_t);
// //     do {
// //         rlen = fread(buf_in, 1, sizeof buf_in, fp_s);
// //         eof = feof(fp_s);
// //         tag = eof ? crypto_secretstream_xchacha20poly1305_TAG_FINAL : 0;
// //         crypto_secretstream_xchacha20poly1305_push(&st, buf_out, &out_len, buf_in, rlen,
// //                                                    NULL, 0, tag);
// //         fwrite(buf_out, 1, (size_t) out_len, fp_t);
// //     } while (! eof);
// //     fclose(fp_t);
// //     fclose(fp_s);
// //     return 0;
// // }

// // static int
// // decrypt(const char *target_file, const char *source_file,
// //         const unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES])
// // {
// //     unsigned char  buf_in [CHUNK_SIZE + crypto_secretstream_xchacha20poly1305_ABYTES];
// //     unsigned char  buf_out[CHUNK_SIZE];
// //     unsigned char  header [crypto_secretstream_xchacha20poly1305_HEADERBYTES];
// //     crypto_secretstream_xchacha20poly1305_state st;
// //     FILE          *fp_t, *fp_s;
// //     unsigned long long out_len;
// //     size_t         rlen;
// //     int            eof;
// //     int            ret = -1;
// //     unsigned char  tag;

// //     fp_s = fopen(source_file, "rb");
// //     fp_t = fopen(target_file, "wb");
// //     fread(header, 1, sizeof header, fp_s);
// //     if (crypto_secretstream_xchacha20poly1305_init_pull(&st, header, key) != 0) {
// //         goto ret; /* incomplete header */
// //     }
// //     do {
// //         rlen = fread(buf_in, 1, sizeof buf_in, fp_s);
// //         eof = feof(fp_s);
// //         if (crypto_secretstream_xchacha20poly1305_pull(&st, buf_out, &out_len, &tag,
// //                                                        buf_in, rlen, NULL, 0) != 0) {
// //             goto ret; /* corrupted chunk */
// //         }
// //         if (tag == crypto_secretstream_xchacha20poly1305_TAG_FINAL && ! eof) {
// //             goto ret; /* premature end (end of file reached before the end of the stream) */
// //         }
// //         fwrite(buf_out, 1, (size_t) out_len, fp_t);
// //     } while (! eof);

// //     ret = 0;
// // ret:
// //     fclose(fp_t);
// //     fclose(fp_s);
// //     return ret;
// // }

// // int
// // main(void)
// // {
// //     unsigned char key[32];

// //     if (sodium_init() != 0) {
// //         return 1;
// //     }
// //     // crypto_secretstream_xchacha20poly1305_keygen(key);
// //     if (encrypt("encrypted", "original", key) != 0) {
// //         return 1;
// //     }
// //     if (decrypt("decrypted", "encrypted", key) != 0) {
// //         return 1;
// //     }
// //     return 0;
// // }

// #include <stdio.h>
// #include <time.h>
// #include <unistd.h> 

// int main (void) {  
//    int i=0;
//       //Структура содержащая время задержки
//    struct timespec tw = {0,35000000};
//    //Структура, в которую будет помещен остаток времени
//    //задержки, если задержка будет прервана досрочно
//    struct timespec tr;

//     while (i < 101) {
//         nanosleep(&tw, &tr);
//         printf ("\r%d",i);
//         fflush (stdout);
//         i++;
//     }
//     return 0;
// }