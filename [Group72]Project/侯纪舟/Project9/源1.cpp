#ifndef SM4_H
#define SM4_H

/**
* \file sm4.h
*/
#define SM4_ENCRYPT     1
#define SM4_DECRYPT     0

/**
* \brief          SM4 context structure �����Ľṹ
*/
typedef struct
{
    int mode;                   /*!<  encrypt/decrypt ���Ƽ��ܻ��ǽ��� */
    unsigned long sk[32];       /*!<  SM4 subkeys  ���ÿ�ε���������Կ     */
}sm4_context;


#ifdef __cplusplus
extern "C" {
#endif
    //
        /**
        * \brief          SM4 key schedule (128-bit, encryption)���ü�����Կ
        *
        * \param ctx      SM4 context to be initialized
        * \param key      16-byte secret key
        */
    void sm4_setkey_enc(sm4_context* ctx, unsigned char key[16]);

    /**
    * \brief          SM4 key schedule (128-bit, decryption)
    *
    * \param ctx      SM4 context to be initialized
    * \param key      16-byte secret key
    */
    void sm4_setkey_dec(sm4_context* ctx, unsigned char key[16]);

    /**
    * \brief          SM4-ECB block encryption/decryption
    * \param ctx      SM4 context
    * \param mode     SM4_ENCRYPT or SM4_DECRYPT
    * \param length   length of the input data
    * \param input    input block
    * \param output   output block
    */
    int sm4_crypt_ecb(sm4_context* ctx,
        int mode,
        int length,
        unsigned char* input,
        unsigned char* output);

    /**
    * \brief          SM4-CBC buffer encryption/decryption
    * \param ctx      SM4 context
    * \param mode     SM4_ENCRYPT or SM4_DECRYPT
    * \param length   length of the input data
    * \param iv       initialization vector (updated after use)
    * \param input    buffer holding the input data
    * \param output   buffer holding the output data
    */
    int sm4_crypt_cbc(sm4_context* ctx,
        int mode,
        int length,
        unsigned char iv[16],
        unsigned char* input,
        unsigned char* output);

#ifdef __cplusplus
}
#endif
#include <iostream>
class Sm4EncDec
{
public:
    /**********************************************************************************************
    * @brief ���캯�� ��Կ��ֵ
    **********************************************************************************************/
    Sm4EncDec(int _mode = 0);

    /**********************************************************************************************
    * @brief ���캯�� ��Կ��ֵ
    * @param SrcPath (����) ��Ҫ��ֵ����Կ
    **********************************************************************************************/
    Sm4EncDec(unsigned char key[], int _mode = 0);

    /**********************************************************************************************
    * @brief �����ļ�
    * @param SrcPath (����) ����Դ�ļ���
    * @param DestPath (����) ���ܺ�������ļ���
    **********************************************************************************************/
    void Encrypt(std::string DestPath, std::string SrcPath);

    /**********************************************************************************************
    * @brief �����ļ�
    * @param SrcPath (����) ����Դ�ļ���
    * @param DestPath (����) ���ܺ�������ļ���
    **********************************************************************************************/
    void Decrypt(std::string DestPath, std::string SrcPath);


    /**********************************************************************************************
    * @brief �����ļ�
    * @param SrcPath (���봫��) ����Դ�ļ���
    **********************************************************************************************/
    void Encrypt(std::string SrcPath);

    /**********************************************************************************************
    * @brief �����ļ�
    * @param SrcPath (���봫��) ����Դ�ļ���
    **********************************************************************************************/
    void Decrypt(std::string SrcPath);


    /**********************************************************************************************
    * @brief �����ַ���
    * @param SrcPath (����) ��Ҫ���ܵ��ַ���
    * @param DestPath (����) ���ܺ�������ַ���
    **********************************************************************************************/
    int Encrypt(unsigned char* destBuf, unsigned char* srcStr, int srcLen);

    /**********************************************************************************************
    * @brief �����ַ���
    * @param SrcPath (����) ��Ҫ���ܵ��ַ���
    * @param DestPath (����) ���ܺ�������ַ���
    **********************************************************************************************/
    int Decrypt(unsigned char* destBuf, unsigned char* srcStr, int srcLen);

    /**********************************************************************************************
    * @brief ���ü���ģʽ
    * @param _mode (����) ����ģʽ
    *   _mode  = 0  --> ebc
    *   _mode  > 0  --> cbc
    **********************************************************************************************/
    void SetMode(int _mode);

private:
    //��Կ
    unsigned char key[16];
    int mode;               //����ģʽ ebc or cbc
};

#endif // SM4_H
