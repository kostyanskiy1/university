using System;
using System.IO;
using Org.BouncyCastle.Crypto.Digests;

public class SHA3Example
{
    public static void Main(string[] args)
    {

        Console.WriteLine("Введите имя файла:");
        string fileName = Console.ReadLine();
        string input;
       
        input = File.ReadAllText( fileName);
            Console.WriteLine("Текст файла:");
            Console.WriteLine(input);
     
        Sha3Digest sha3 = new Sha3Digest(256); // choose the hash size of 256 bits

        byte[] data = System.Text.Encoding.UTF8.GetBytes(input);
       
        sha3.BlockUpdate(data, 0, data.Length);

        byte[] hash = new byte[sha3.GetDigestSize()];

        sha3.DoFinal(hash, 0);

     
        Console.WriteLine(BitConverter.ToString(hash).Replace("-", ""));


        Console.WriteLine("Введите имя файла для записи хеша:");
         fileName = Console.ReadLine();
        //string dataWithNewLine = "\r\n"+ BitConverter.ToString(hash).Replace("-", ""); // добавляем символ новой строки
        string dataWithNewLine =  BitConverter.ToString(hash).Replace("-", ""); // добавляем символ новой строки

        // открываем файл для записи в конец файла
        using (var stream = new FileStream(fileName, FileMode.Append))
        {
            byte[] dataBytes = System.Text.Encoding.UTF8.GetBytes(dataWithNewLine);
            // записываем данные в конец файла
            stream.Write(dataBytes, 0, dataBytes.Length);
           
        }

        Console.WriteLine("Данные успешно записаны в конец файла");



        Console.WriteLine("Введите имя файла с хешем для его проверки:");
        fileName = Console.ReadLine();
    
        input = File.ReadAllText(fileName);
        Console.WriteLine("Текст файла:");
        Console.WriteLine(input);

        Console.WriteLine("Введите новое слово для проверки:");
        string newword = Console.ReadLine();

        byte[] newdata = System.Text.Encoding.UTF8.GetBytes(newword);

        sha3.BlockUpdate(newdata, 0, newdata.Length);

        byte[] newh = new byte[sha3.GetDigestSize()];

        sha3.DoFinal(newh, 0);

        string newhash = BitConverter.ToString(newh).Replace("-", ""); // добавляем символ новой строки


        if (newhash.Equals(input) == true){
            Console.WriteLine("Слова совпадают!");
        } else Console.WriteLine("Слова не совпадают!");
   
    }
}