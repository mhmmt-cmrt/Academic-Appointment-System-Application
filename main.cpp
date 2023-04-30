#include<iostream>
#include<string>
#include<fstream>
#include<array>
#include <iomanip>
#include <locale.h>
#include <ctime>
#include "windows.h"
#include <ctype.h>
#include "header.h"

using namespace std;

//  created by muhammet Cömert
/*main fonksiyonu uzerinde pek fazla is yuku bulunmamaktadir.
burada sadece kullanicidan islem yapacagi birim ve birim uzerinde
yapacagi islemi menudeki numaralara gore alir ve aldýgý bu numaralarý
islemsecme fonksiyonuna gonderir daha sonra ýslem secme fonksiyonu da
gerekli sýnýf ve uye fonksiyonlarini kosar.daha sonra main secimlerden
sonra consolu temizler ve son olarakta kullanicinin devam edip etmeme
durumunu sorgular. devam etmeyecekse programi sonlandirir.
devam edecekse main fonksiyonunun basina yani secimlere geri doner.*/

int main()
{
	int iBirim, iIslem, iDeger; //secimlerin tutulacagi degiskenler
	system("CLS");

	// kullanicinin islem yapacagi birim seciliyor.
	cout << "\nislem yapmak istediginiz birimi secin" << endl;
	cout << "-------------------------------------\n";
	cout << "[1] Ogrenci islemleri" << endl;
	cout << "[2] Akademisyen islemleri" << endl;
	cout << "[3] Randevu islemleri" << endl;
	cout << "-------------------------------------\n";
	cout << "->"; cin >> iBirim;

	if (iBirim < 4 && iBirim > 0) {}
	else
		cout << "yanlis deger girildi. tekrar baslatin\n" << endl;

	// kullanicinin birim uzerinde hangi islemi yapacagi seciliyor
	cout << "\nyapmak istediginiz islemi secin" << endl;
	cout << "-------------------------------------\n";
	cout << "[1] Ekleme islemi" << endl;
	cout << "[2] Silme islemi" << endl;
	cout << "[3] Guncelle" << endl;
	cout << "[4] listeleme islemi" << endl;

	if (iBirim == 1 || iBirim == 2)
	{
		cout << "[5] Randevu Sorgulama" << endl;
	}
	cout << "-------------------------------------\n";
	cout << "->"; cin >> iIslem;

	if (iIslem < 6 && iIslem > 0) {}
	else
		cout << "yanlis deger girildi. tekrar baslatin" << endl;

	system("CLS"); //ekran temizleniyor.

	// secilen birim ve isleme uygun klas ve uye fonk. setleniyor
	islemSecme(iBirim, iIslem);

	// devam etme istegi sorgulaniyor.
	cout << "Devam etmek istiyormusunuz : " << endl;
	cout << "[1] = Evet" << endl;
	cout << "[2] = Hayir" << endl;
	cin >> iDeger;

	if (iDeger == 1) { return main(); }
	else
		return 0;
}