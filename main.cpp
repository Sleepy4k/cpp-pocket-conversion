#include <string> // Import library string yaitu untuk menggunakan tipe data string
#include <vector> // Import library vector yaitu array dinamis (ukuran array dapat diubah)
#include <iomanip> // Import library iomanip yaitu manipulasi data decimal
#include <iostream> // Import library iostream yaitu untuk input dan output

/**
 * Import beberapa fungsi dari namespace std
 * 
 * std::cin = untuk mengambil inputan user
 * std::cout = untuk menampilkan output
 * std::endl = untuk membuat baris baru
 * std::string = untuk membuat string
 * std::vector = untuk membuat vector (array dinamis)
 * std::to_string = untuk mengubah tipe data apapun menjadi string
*/
using std::cin; // Menggunakan std::cin
using std::cout; // Menggunakan std::cout
using std::endl; // Menggunakan std::endl
using std::fixed; // Menggunakan std::fixed
using std::string; // Menggunakan std::string
using std::vector; // Menggunakan std::vector
using std::to_string; // Menggunakan std::to_string
using std::setprecision; // Menggunakan std::setprecision

/**
 * @brief Deklarasi variable global
 * 
 * isDevMode = untuk mengetahui apakah program berjalan di mode development atau tidak
 * 
 * Jika isDevMode = true, maka program akan menampilkan pesan "Mode development aktif"
 * dan program akan menampilkan lebih banyak informasi
 */
bool isDevMode = false;

/**
 * @brief Deklarasi variable global
 * 
 * indexResult = untuk menyimpan index result
 * indexResult digunakan untuk menampilkan hasil konversi
 * indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
 * indexResult = 0 karena indexResult akan direset ketika program dijalankan
 */
int indexResult = 0;

/**
 * @brief Deklarasi variable global
 * 
 * indexHistorySuhu = untuk menyimpan index history suhu
 * indexHistoryPanjang = untuk menyimpan index history panjang
 * indexHistoryBerat = untuk menyimpan index history berat
 * index = 0 karena index direset ketika program dijalankan
 */
int indexHistorySuhu = 0, indexHistoryPanjang = 0, indexHistoryBerat = 0;

/**
 * @brief Deklarasi struct History
 * 
 * data = untuk menyimpan data awal
 * result = untuk menyimpan hasil konversi
 * rumus = untuk menyimpan rumus konversi
 * 
 * Note : struct adalah tipe data yang dapat menyimpan beberapa tipe data dan dapat digunakan untuk membuat object
 */
struct History {
  string data;
  string result;
  string rumus;
};

/**
 * @brief Deklarasi array 3 dimensi secara global
 * 
 * historyData = untuk menyimpan history data
 * historyData[3] = untuk menyimpan 3 jenis data (suhu, panjang, berat)
 * historyData[3][50] = untuk menyimpan 50 data untuk setiap jenis data
 * historyData[3][50][3] = untuk menyimpan 3 data untuk setiap data (data awal, hasil konversi, rumus)
 */
History historyData[3][50][3];

/**
 * @brief Menampilkan pesan debug
 * 
 * @param message pesan yang akan ditampilkan ke user - string
 * @param value value yang akan ditampilkan ke user - string
 *
 * @return void
 */
void debug(string message, string value);

/**
 * @brief Membersihkan layar terminal (Windows & Linux)
 *
 * @return void
 */
void clearScreen(); // Deklarasi fungsi clearScreen

/**
 * @brief Pause program hingga user menekan tombol apapun
 *
 * @return void
 */
void pauseScreen(); // Deklarasi fungsi pauseScreen

/**
 * @brief Mengambil inputan user dan mengembalikan nilai inputan user
 * 
 * @param message pesan yang akan ditampilkan ke user - string
 * 
 * @return T
 */
template <typename T> T inputData(string message);

/**
 * @brief Memasukkan data ke history
 * 
 * @param data yaitu data awal yang akan dimasukkan ke history - string
 * @param result yaitu hasil konversi yang akan dimasukkan ke history - string
 * @param rumus yaitu rumus konversi yang akan dimasukkan ke history - string
 * @param jenisData yaitu jenis data yang akan dimasukkan ke history - integer
 *
 * @return void
 */
void handleHistory(string data, string result, string rumus, int jenisData);

/**
 * @brief Menampilkan history
 * 
 * @param jenisData yaitu jenis data yang akan ditampilkan - integer
 *
 * @return void
 */
void menampilkanHistory(int jenisData);

/**
 * @brief Konversi suhu (celcius, fahrenheit, kelvin)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiSuhu(int *input, int *totalData, vector<float> *data, vector<float> *result); // Deklarasi fungsi konversiSuhu

/**
 * @brief Konversi panjang (kilometer, meter, centimeter)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiPanjang(int *input, int *totalData, vector<float> *data, vector<float> *result); // Deklarasi fungsi konversiPanjang

/**
 * @brief Konversi berat (gram, kilogram, ons)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiBerat(int *input, int *totalData, vector<float> *data, vector<float> *result); // Deklarasi fungsi konversiBerat

/**
 * @brief Main program
 *
 * @return int
 */
int main() {
  /**
   * Input = untuk menyimpan inputan user (pilihan menu)
   * totalData = untuk menyimpan jumlah data yang akan dikonversi
   */
  int input, totalData;

  /**
   * isOnRepeat = untuk menyimpan status program (true = program berjalan, false = program berhenti)
   */
  bool isOnRepeat = true;

  /**
   * data = untuk menyimpan data yang akan dikonversi
   * result = untuk menyimpan hasil konversi
   */
  vector<float> data, result;

  /**
   * Register setprecision untuk handle data yang mencapai nilai jutaan
   * Hal ini untuk menghindari data yang diubah menjadi notasi ilmiah
   * Contoh : 1000000 menjadi 1e+06
   */
  cout << fixed << setprecision(0);

  clearScreen(); // Membersihkan layar terminal

  // Menampilkan pesan "Mode development aktif" jika isDevMode = true
  debug("main", "Mode development aktif, menjalankan fungsi main");

  /**
   * Looping akan berjalan selama variable isOnRepeat = true
   * Ketika user memilih keluar, maka variable isOnRepeat akan diubah menjadi false
   * 
   * Pada perulangan ini kita menggunakan do while
   * Karena kita ingin menjalankan program terlebih dahulu sebelum melakukan pengecekan kondisi
   */
  do {
    cout << "Selamat datang di posion (pocket conversion)" << endl;
    cout << "--------------------------------" << endl;
    cout << "1) Konversi Suhu" << endl;
    cout << "2) Konversi Panjang" << endl;
    cout << "3) Konversi Berat" << endl;
    cout << "4) Keluar" << endl;
    cout << "--------------------------------" << endl;

    // Mengambil inputan user dan menyimpannya ke variable input
    input = inputData<int>("Masukkan pilihan: ");

    clearScreen(); // Membersihkan layar terminal

    // Menampilkan value inputan user
    debug("main", "Inputan user: " + to_string(input));

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan fungsi konversi
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 3 karena pilihan 4 adalah untuk keluar (isOnRepeat = false)
     */
    switch (input) {
      case 1:
        // Menampilkan ke user bahwa program akan menjalankan fungsi konversi suhu
        debug("main", "Menjalankan fungsi konversi suhu, mengirimkan alamat variable input, totalData, data, result ke fungsi konversiSuhu");

        // Mengirimkan alamat variable input, totalData, data, result ke fungsi konversiSuhu
        konversiSuhu(&input, &totalData, &data, &result);
        break;
      case 2:
        // Menampilkan ke user bahwa program akan menjalankan fungsi konversi panjang
        debug("main", "Menjalankan fungsi konversi panjang, mengirimkan alamat variable input, totalData, data, result ke fungsi konversiPanjang");

        // Mengirimkan alamat variable input, totalData, data, result ke fungsi konversiPanjang
        konversiPanjang(&input, &totalData, &data, &result);
        break;
      case 3:
        // Menampilkan ke user bahwa program akan menjalankan fungsi konversi berat
        debug("main", "Menjalankan fungsi konversi berat, mengirimkan alamat variable input, totalData, data, result ke fungsi konversiBerat");

        // Mengirimkan alamat variable input, totalData, data, result ke fungsi konversiBerat
        konversiBerat(&input, &totalData, &data, &result);
        break;
      case 4:
        // Menampilkan ke user bahwa program akan keluar
        debug("main", "Variable isOnRepeat diubah menjadi false, program akan keluar");

        // Ketika user memilih keluar, variable isOnRepeat akan diubah menjadi false
        isOnRepeat = false;
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
        break;
    }
  } while (isOnRepeat); // ketika variable isOnRepeat = false maka program akan berhenti

  cout << "Terima kasih telah menggunakan posion (pocket conversion)" << endl;

  // Mengecek apakah program berjalan hingga akhir atau tidak
  debug("main", "Keluar dari fungsi main");

  return 0; // Keluar dari program dengan status 0 (berhasil)
}

/**
 * @brief Membersihkan layar terminal (Windows & Linux)
 *
 * @return void
 */
void clearScreen() {
  /**
   * #ifdef adalah preprocessor directive yang digunakan untuk mengecek apakah suatu macro sudah didefinisikan atau belum
   * #endif adalah untuk mengakhiri preprocessor directive 
   * 
   * #ifdef _WIN32 adalah untuk mengecek apakah program dijalankan di Windows atau tidak
   * Jika program dijalankan di Windows, maka akan menjalankan system("cls")
   * Jika program dijalankan di Linux, maka akan menjalankan system("clear")
   * system("cls") digunakan untuk membersihkan layar terminal di Windows
   * system("clear") digunakan untuk membersihkan layar terminal di Linux
   */
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif

  // Memastikan bahwa layar terminal sudah bersih
  debug("clearScreen", "Berhasil membersihkan layar terminal");
}

/**
 * @brief Pause program hingga user menekan tombol apapun
 *
 * @return void
 */
void pauseScreen() {
  // Menjalankan inisialisasi fungsi pauseScreen
  debug("pauseScreen", "Menjalankan fungsi pauseScreen");

  /**
   * #ifdef adalah preprocessor directive yang digunakan untuk mengecek apakah suatu macro sudah didefinisikan atau belum
   * #endif adalah untuk mengakhiri preprocessor directive 
   * 
   * #ifdef _WIN32 adalah untuk mengecek apakah program dijalankan di Windows atau tidak
   * Jika program dijalankan di Windows, maka akan menjalankan system("pause")
   * Jika program dijalankan di Linux, maka akan menjalankan system("read -n 1 -s -p \"\"")
   * system("pause") adalah fungsi untuk menjeda aplikasi hingga user menekan tombol apapun
   * system("read -n 1 -s -p \"\"") adalah perintah untuk mengambil inputan user tanpa menampilkan inputan user
   */
  #ifdef _WIN32
    /**
     * system("pause") adalah fungsi untuk menjeda aplikasi hingga user menekan tombol apapun
     * Pada kasus ini kita hanya membutuhkan inputan user untuk melanjutkan program
     */
    system("pause");
  #else
    cout << "Tekan tombol apapun untuk melanjutkan..." << endl;

    /**
     * read -n 1 -s -p "" adalah perintah untuk mengambil inputan user tanpa menampilkan inputan user
     * Pada kasus ini kita hanya membutuhkan inputan user untuk melanjutkan program
     */
    system("read -n 1 -s -p \"\"");
  #endif

  clearScreen(); // Membersihkan layar terminal

  // Memastikan bahwa program sudah di pause dan melanjutkan program
  debug("pauseScreen", "Berhasil menjalankan fungsi pauseScreen");
}

/**
 * @brief Mengambil inputan user dan mengembalikan nilai inputan user
 * 
 * @param message pesan yang akan ditampilkan ke user - string
 * 
 * @return T
 */
template <typename T> T inputData(string message) {
  // Menjalankan inisialisasi fungsi inputData
  debug("inputData", "Menjalankan fungsi inputData");

  /**
   * Deklarasi variable input
   * Variable bersifat lokal karena dideklarasikan di dalam fungsi
   * Variable input akan menyimpan hasil inputan user
   * T adalah tipe data yang akan digunakan (int, float, double, string, char)
   */
  T input;

  // Menampilkan pesan yang diberikan ke user
  cout << message;

  // Mengambil inputan user dan menyimpannya ke variable input
  // Jika T adalah float atau double, maka inputan user akan diubah menjadi float atau double 
  cin >> input;

  // Memastikan bahwa program sudah mengambil inputan user dan mengembalikan nilai input
  debug("inputData", "Berhasil menjalankan fungsi inputData");

  // Mengembalikan nilai input
  return input;
}

/**
 * @brief Memasukkan data ke history
 * 
 * @param data yaitu data awal yang akan dimasukkan ke history - string
 * @param result yaitu hasil konversi yang akan dimasukkan ke history - string
 * @param rumus yaitu rumus konversi yang akan dimasukkan ke history - string
 * @param jenisData yaitu jenis data yang akan dimasukkan ke history - integer
 *
 * @return void
 */
void handleHistory(string data, string result, string rumus, int jenisData) {
  // Jika jenisData tidak tersedia, akan keluar dari fungsi
  if (jenisData < 1 || jenisData > 3) {
    cout << "Proses menyimpan history gagal, jenis data tidak tersedia" << endl;
    return;
  }

  /**
   * indexHistory = untuk menyimpan index history data
   * indexHistory digunakan untuk menentukan index history data
   */
  int *indexHistory;

  /**
   * Percabangan untuk menentukan indexHistory
   * Ketika jenisData = 1, maka indexHistory = &indexHistorySuhu
   * Ketika jenisData = 2, maka indexHistory = &indexHistoryPanjang
   * Ketika jenisData = 3, maka indexHistory = &indexHistoryBerat
   */
  if (jenisData == 1) indexHistory = &indexHistorySuhu;
  else if (jenisData == 2) indexHistory = &indexHistoryPanjang;
  else if (jenisData == 3) indexHistory = &indexHistoryBerat;

  // Mengubah value jenisData menjadi index historyData
  jenisData--;

  historyData[jenisData][*indexHistory]->data = data; // Menyimpan data awal ke historyData
  historyData[jenisData][*indexHistory]->result = result; // Menyimpan hasil konversi ke historyData
  historyData[jenisData][*indexHistory]->rumus = rumus; // Menyimpan rumus ke historyData

  // indexHistory++ digunakan untuk menambahkan indexHistory sebanyak 1
  (*indexHistory)++;
}

/**
 * @brief Menampilkan history
 * 
 * @param jenisData yaitu jenis data yang akan ditampilkan - integer
 *
 * @return void
 */
void menampilkanHistory(int jenisData) {
  // Jika jenisData tidak tersedia, akan keluar dari fungsi
  if (jenisData < 1 || jenisData > 3) {
    cout << "Proses menampilkan history gagal, jenis data tidak tersedia" << endl;
    return;
  }

  /**
   * namaHistory = untuk menyimpan nama history data
   * namaHistory digunakan untuk menentukan nama history data
   */
  string namaHistory;

  /**
   * Percabangan untuk menentukan nama history
   * Ketika jenisData = 1, maka namaHistory = "Suhu"
   * Ketika jenisData = 2, maka namaHistory = "Panjang"
   * Ketika jenisData = 3, maka namaHistory = "Berat"
   */
  if (jenisData == 1) namaHistory = "Suhu";
  else if (jenisData == 2) namaHistory = "Panjang";
  else if (jenisData == 3) namaHistory = "Berat";

  /**
   * historyType = untuk menyimpan jenis history data
   * historyType digunakan untuk menentukan jenis history data
   */
  int historyType;

  // Menampilkan jenis history data
  cout << "Menu history " << namaHistory << endl;
  cout << "--------------------------------" << endl;
  cout << "1) Hasil Terlama ke terbaru" << endl;
  cout << "2) Hasil Terbaru ke terlama" << endl;
  cout << "3) Hasil tertinggi ke terendah" << endl;
  cout << "4) Hasil terendah ke tertinggi" << endl;
  cout << "5) Mencari data" << endl;
  cout << "6) Kembali" << endl;
  cout << "--------------------------------" << endl;

  // Menanyakan user ingin melihat history jenis data apa
  historyType = inputData<int>("Masukan pilihan anda: ");

  clearScreen(); // Membersihkan layar terminal

  // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
  if (historyType == 6) return;
  else if (historyType < 1 || historyType > 6) {
    // Ketika user memilih pilihan yang tidak tersedia
    cout << "Proses menampilkan history gagal, pilihan tidak tersedia" << endl;
    return;
  }

  /**
   * indexHistory = untuk menyimpan index history data
   * indexHistory digunakan untuk menentukan index history data
   */
  int indexHistory;

  /**
   * Percabangan untuk menentukan indexHistory dan namaHistory
   * Ketika jenisData = 1, maka indexHistory = indexHistorySuhu
   * Ketika jenisData = 2, maka indexHistory = indexHistoryPanjang 
   * Ketika jenisData = 3, maka indexHistory = indexHistoryBerat
   */
  if (jenisData == 1) indexHistory = indexHistorySuhu;
  else if (jenisData == 2) indexHistory = indexHistoryPanjang;
  else if (jenisData == 3) indexHistory = indexHistoryBerat;

  // Mengubah value jenisData menjadi index historyData
  jenisData--;

  // Menampilkan history data
  if (historyType != 5) {
    cout << "History Konversi " << namaHistory << endl;
    cout << "Total data: " << indexHistory << endl;
    cout << "--------------------------------" << endl;
  }

  if (indexHistory == 0) {
    // Ketika indexHistory = 0, maka tidak ada history data
    cout << "Belum ada history yang tersedia" << endl;
    cout << "--------------------------------" << endl;
    goto ending; // Loncat ke label ending untuk mengakhiri program
  }

  if (historyType == 1) {
    /**
     * Looping sebanyak indexHistory untuk menampilkan history data
     * Mengambil data dari historyData[jenisData][0] yaitu data awal
     * Dengan ini kita menampilkan data dari terlama ke terbaru
     */
    for (int i = 0; i < indexHistory; i++) {
      cout << "Data awal: " << historyData[jenisData][i]->data << endl; // Menampilkan data awal
      cout << "Hasil konversi: " << historyData[jenisData][i]->result << endl; // Menampilkan hasil konversi
      cout << "Rumus: " << historyData[jenisData][i]->rumus << endl; // Menampilkan rumus
      cout << "--------------------------------" << endl;
    }
  } else if (historyType == 2) {
    /**
     * Looping sebanyak indexHistory untuk menampilkan history data
     * Mengambil data dari historyData[jenisData][indexHistory - 1] yaitu data terbaru
     * Dengan ini kita menampilkan data dari terbaru ke terlama
     */
    for (int i = indexHistory - 1; i >= 0; i--) {
      cout << "Data awal: " << historyData[jenisData][i]->data << endl; // Menampilkan data awal
      cout << "Hasil konversi: " << historyData[jenisData][i]->result << endl; // Menampilkan hasil konversi
      cout << "Rumus: " << historyData[jenisData][i]->rumus << endl; // Menampilkan rumus
      cout << "--------------------------------" << endl;
    }
  } else if (historyType == 3) {
    // Mendeklarasi variable untuk menampung data yang akan diurutkan ke vector data
    vector<float> data;

    /**
     * Melakukan looping sebanyak total indexHistory
     * untuk mengambil data dari historyData[jenisData][i][1] yaitu hasil konversi
     * 
     * Note : stof adalah fungsi untuk mengubah string menjadi float
     * Note : push_back adalah fungsi untuk menambahkan data ke vector
     */
    for (int i = 0; i < indexHistory; i++) {
      data.push_back(stof(historyData[jenisData][i]->result));
    }

    /**
     * Looping sebanyak total indexHistory
     * Pada nested loop ini kita akan melakukan perbandingan data
     * Jika data[i] lebih kecil dari data[j], maka data[i] akan ditukar dengan data[j]
     * Agar data terurut dari yang terbesar ke terkecil
     */
    for (int i = 0; i < indexHistory; i++) {
      for (int j = i + 1; j < indexHistory; j++) {
        // Jika data[i] lebih kecil dari data[j], maka data[i] akan ditukar dengan data[j]
        if (data[i] < data[j]) {
          float temp = data[i]; // Mendeklarasi variable temp untuk menyimpan data[i]
          data[i] = data[j]; // Mengubah data[i] menjadi data[j]
          data[j] = temp; // Mengubah data[j] menjadi temp (data[i])
        }
      }
    }

    /**
     * Looping sebanyak total indexHistory
     * Mengambil data dari historyData[jenisData][i][1] yaitu hasil konversi
     * Dan kita bandingkan dengan hasil konversi yang sudah diurutkan
     * Dengan ini kita menampilkan data dari tertinggi ke terendah
     * 
     * Note : stof adalah fungsi untuk mengubah string menjadi float
     */
    for (int i = 0; i < indexHistory; i++) {
      for (int j = 0; j < indexHistory; j++) {
        // Jika data[i] sama dengan historyData[jenisData][j][1], maka kita tampilkan data awal, hasil konversi, dan rumus
        if (data[i] == stof(historyData[jenisData][j]->result)) {
          cout << "Data awal: " << historyData[jenisData][j]->data << endl; // Menampilkan data awal
          cout << "Hasil konversi: " << historyData[jenisData][j]->result << endl; // Menampilkan hasil konversi
          cout << "Rumus: " << historyData[jenisData][j]->rumus << endl; // Menampilkan rumus
          cout << "--------------------------------" << endl;
        }
      }
    }
  } else if (historyType == 4) {
    // Mendeklarasi variable untuk menampung data yang akan diurutkan ke vector data
    vector<float> data;

    /**
     * Melakukan looping sebanyak total indexHistory
     * untuk mengambil data dari historyData[jenisData][i][1] yaitu hasil konversi
     * 
     * Note : stof adalah fungsi untuk mengubah string menjadi float
     * Note : push_back adalah fungsi untuk menambahkan data ke vector
     */
    for (int i = 0; i < indexHistory; i++) {
      data.push_back(stof(historyData[jenisData][i]->result));
    }

    /**
     * Looping sebanyak total indexHistory
     * Pada nested loop ini kita akan melakukan perbandingan data
     * Jika data[i] lebih besar dari data[j], maka data[i] akan ditukar dengan data[j]
     * Agar data terurut dari yang terkecil ke terbesar
     */
    for (int i = 0; i < indexHistory; i++) {
      for (int j = i + 1; j < indexHistory; j++) {
        // Jika data[i] lebih besar dari data[j], maka data[i] akan ditukar dengan data[j]
        if (data[i] > data[j]) {
          float temp = data[i]; // Mendeklarasi variable temp untuk menyimpan data[i]
          data[i] = data[j]; // Mengubah data[i] menjadi data[j]
          data[j] = temp; // Mengubah data[j] menjadi temp (data[i])
        }
      }
    }

    /**
     * Looping sebanyak total indexHistory
     * Mengambil data dari historyData[jenisData][i][1] yaitu hasil konversi
     * Dan kita bandingkan dengan hasil konversi yang sudah diurutkan
     * Dengan ini kita menampilkan data dari tertinggi ke terendah
     * 
     * Note : stof adalah fungsi untuk mengubah string menjadi float
     */
    for (int i = 0; i < indexHistory; i++) {
      for (int j = 0; j < indexHistory; j++) {
        // Jika data[i] sama dengan historyData[jenisData][j][1], maka kita tampilkan data awal, hasil konversi, dan rumus
        if (data[i] == stof(historyData[jenisData][j]->result)) {
          cout << "Data awal: " << historyData[jenisData][j]->data << endl; // Menampilkan data awal
          cout << "Hasil konversi: " << historyData[jenisData][j]->result << endl; // Menampilkan hasil konversi
          cout << "Rumus: " << historyData[jenisData][j]->rumus << endl; // Menampilkan rumus
          cout << "--------------------------------" << endl;
        }
      }
    }
  } else {
    // Mendeklarasi variable untuk menampung data yang akan diurutkan ke vector data
    string dataSearch;
    vector<string> data;
    bool isFound = false;

    // Menampilkan menu untuk mencari data
    cout << "Mencari data" << endl;
    cout << "--------------------------------" << endl;
    cout << "1) Data awal" << endl;
    cout << "2) Hasil konversi" << endl;
    cout << "3) Kembali" << endl;
    cout << "--------------------------------" << endl;

    // Menanyakan user akan memilih data awal atau hasil konversi
    int pilihan = inputData<int>("Masukan pilihan anda: ");

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (pilihan == 3) menampilkanHistory(jenisData + 1);
    else if (pilihan < 1 || pilihan > 2) { // Ketika user memilih pilihan yang tidak tersedia
      cout << "Proses menampilkan history gagal, pilihan tidak tersedia" << endl;
      return;
    }

    clearScreen(); // Membersihkan layar terminal

    // Menanyakan user data yang akan dicari
    dataSearch = inputData<string>("Masukan data yang akan dicari: ");

    // Memvalidasi inputan user apakah kosong atau tidak
    if (dataSearch.empty()) {
      cout << "Proses menampilkan history gagal, data tidak boleh kosong" << endl;
      return;
    }

    // Deklarasi variable temp untuk menyimpan data yang sudah dipisah
    string tempData;

    /**
     * Melakukan looping sebanyak total indexHistory
     * untuk mengambil data dari historyData[jenisData][i][pilihan] yaitu data awal atau hasil konversi
     * 
     * Note : stof adalah fungsi untuk mengubah string menjadi float
     * Note : push_back adalah fungsi untuk menambahkan data ke vector
     */
    for (int i = 0; i < indexHistory; i++) {
      // Mengambil data berdasarkan pilihan user
      switch (pilihan) {
        case 1:
          tempData = historyData[jenisData][i]->data;
          break;
        case 2:
          tempData = historyData[jenisData][i]->result;
          break;
        default:
          break;
      }

      /**
       * Memisahkan antara hasil konversi dengan satuan konversi
       * Contoh "72.13821 KM" menjadi hanya "72.13821"
       * Agar proses pencarian lebih mudah
       */
      tempData = tempData.substr(0, tempData.find(" "));

      /**
       * Memasukan hasil pemisahan pada temp data ke variable data
       * Proses ini menggunakan system push back
       * 
       * Note : push_back adalah fungsi untuk menambahkan data ke vector
       */
      data.push_back(tempData);
    }

    /**
     * Looping sebanyak total indexHistory
     * Mengambil data dari historyData[jenisData][i][1] yaitu hasil konversi
     * Dan kita bandingkan dengan hasil konversi yang sudah diurutkan
     * Dengan ini kita menampilkan data dari tertinggi ke terendah
     * 
     * Note : stof adalah fungsi untuk mengubah string menjadi float
     */
    for (int i = 0; i < indexHistory; i++) {
      // Mencari apakah data yang dicari ada di dalam vector data
      size_t pos = data[i].find(dataSearch);

      // Jika data ditemukan, maka kita tampilkan data awal, hasil konversi, dan rumus
      if (pos != string::npos) {
        cout << "Data awal: " << historyData[jenisData][i]->data << endl; // Menampilkan data awal
        cout << "Hasil konversi: " << historyData[jenisData][i]->result << endl; // Menampilkan hasil konversi
        cout << "Rumus: " << historyData[jenisData][i]->rumus << endl; // Menampilkan rumus
        cout << "--------------------------------" << endl;

        isFound = true; // Mengubah value isFound menjadi true
      }
    }

    // Ketika data tidak ditemukan
    if (!isFound) {
      cout << "Data tidak ditemukan" << endl;
      cout << "--------------------------------" << endl;
    }
  }

  ending: // Label ending untuk mengakhiri program
  pauseScreen(); // Pause program hingga user menekan tombol apapun
}

/**
 * @brief Konversi suhu (celcius, fahrenheit, kelvin)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiSuhu(int *input, int *totalData, vector<float> *data, vector<float> *result) {
  /**
   * Looping akan berjalan selama true (selama program berjalan)
   * Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
   * Untuk kembali ke menu utama cukup dengan break untuk menghentikan looping
   */
  while (true) {
    cout << "Konversi Suhu" << endl;
    cout << "--------------------------------" << endl;
    cout << "1) Celcius ke Fahrenheit" << endl;
    cout << "2) Celcius ke Kelvin" << endl;
    cout << "3) Fahrenheit ke Celcius" << endl;
    cout << "4) Fahrenheit ke Kelvin" << endl;
    cout << "5) Kelvin ke Celcius" << endl;
    cout << "6) Kelvin ke Fahrenheit" << endl;
    cout << "7) Lihat History" << endl;
    cout << "8) Kembali" << endl;
    cout << "--------------------------------" << endl;

    // Mengambil inputan user dan menyimpannya ke variable input dengan pointer
    *input = inputData<int>("Masukkan pilihan: ");

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 8) break;
    else if (*input > 0 && *input < 7) { // range pilihan hanya 1 - 6 karena 7 adalah untuk melihat history
      // Mengambil inputan user dan menyimpannya ke variable totalData dengan pointer
      *totalData = inputData<int>("Masukan jumlah data suhu yang akan dikonversi: ");

      // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
      (*totalData > 1) ? data->resize(*totalData) : data->resize(1);
    }

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan konversi suhu
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 7 karena pilihan 8 adalah untuk kembali ke menu utama (break)
     */
    switch (*input) {
      case 1:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan suhu ke-" + to_string(i + 1) + " dalam celcius: ");

          // Convert data ke hasil
          float hasil = ((*data)[i] * 9 / 5) + 32;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " C", to_string(hasil) + " F", "(data * 9 / 5) + 32", 1);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " C = " << to_string((*result)[indexResult]) << " F" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan suhu ke-" + to_string(i + 1) + " dalam celcius: ");

          // Convert data ke hasil
          float hasil = (*data)[i] + 273.15;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " C", to_string(hasil) + " K", "data + 273.15", 1);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " C = " << to_string((*result)[indexResult]) << " K" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan suhu ke-" + to_string(i + 1) + " dalam fahrenheit: ");

          // Convert data ke hasil
          float hasil = ((*data)[i] - 32) * 5 / 9;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " F", to_string(hasil) + " C", "(data - 32) * 5 / 9", 1);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " F = " << to_string((*result)[indexResult]) << " C" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan suhu ke-" + to_string(i + 1) + " dalam fahrenheit: ");

          // Convert data ke hasil
          float hasil = ((*data)[i] - 32) * 5 / 9 + 273.15;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " F", to_string(hasil) + " K", "(data - 32) * 5 / 9 + 273.15", 1);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " F = " << to_string((*result)[indexResult]) << " K" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan suhu ke-" + to_string(i + 1) + " dalam kelvin: ");

          // Convert data ke hasil
          float hasil = (*data)[i] - 273.15;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back((*data)[i] - 273.15);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " K", to_string(hasil) + " C", "data - 273.15", 1);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " K = " << to_string((*result)[indexResult]) << " C" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan suhu ke-" + to_string(i + 1) + " dalam kelvin: ");

          // Convert data ke hasil
          float hasil = ((*data)[i] - 273.15) * 9 / 5 + 32;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " K", to_string(hasil) + " F", "(data - 273.15) * 9 / 5 + 32", 1);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " K = " << to_string((*result)[indexResult]) << " F" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 7:
        /**
         * Menampilkan history konversi
         * Parameter 1 yaitu untuk menentukan jenis data
         * 1 = suhu
         * 2 = panjang
         * 3 = berat
         */
        menampilkanHistory(1);
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Konversi panjang (kilometer, meter, centimeter)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiPanjang(int *input, int *totalData, vector<float> *data, vector<float> *result) {
  /**
   * Looping akan berjalan selama true (selama program berjalan)
   * Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
   * Untuk kembali ke menu utama cukup dengan break untuk menghentikan looping
   */
  while (true) {
    cout << "--------------------------------" << endl;
    cout << "1) Kilometer ke Meter" << endl;
    cout << "2) Kilometer ke Centimeter" << endl;
    cout << "3) Meter ke Kilometer" << endl;
    cout << "4) Meter ke Centimeter" << endl;
    cout << "5) Centimeter ke Kilometer" << endl;
    cout << "6) Centimeter ke Meter" << endl;
    cout << "7) Lihat History" << endl;
    cout << "8) Kembali" << endl;
    cout << "--------------------------------" << endl;

    // Mengambil inputan user dan menyimpannya ke variable input dengan pointer
    *input = inputData<int>("Masukkan pilihan: ");

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 8) break;
    else if (*input > 0 && *input < 7) {
      // Mengambil inputan user dan menyimpannya ke variable totalData dengan pointer
      *totalData = inputData<float>("Masukan jumlah data panjang yang akan dikonversi: ");

      // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
      (*totalData > 1) ? data->resize(*totalData) : data->resize(1);
    }

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan konversi panjang
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 7 karena pilihan 8 adalah untuk kembali ke menu utama (break)
     */
    switch (*input) {
      case 1:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan panjang ke-" + to_string(i + 1) + " dalam kilometer: ");

          // Convert data ke hasil
          float hasil = (*data)[i] * 1000;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " KM", to_string(hasil) + " M", "(data * 1000)", 2);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++){
          cout << to_string((*data)[i]) << " km = " << to_string((*result)[indexResult]) << " m" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan panjang ke-" + to_string(i + 1) + " dalam kilometer: ");

          // Convert data ke hasil
          float hasil = (*data)[i] * 100000;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " KM", to_string(hasil) + " CM", "(data * 100000)", 2);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " km = " << to_string((*result)[indexResult]) << " cm" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan panjang ke-" + to_string(i + 1) + " dalam meter: ");

          // Convert data ke hasil
          float hasil = (*data)[i] / 1000;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " M", to_string(hasil) + " KM", "(data / 1000)", 2);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " m = " << to_string((*result)[indexResult]) << " km" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan panjang ke-" + to_string(i + 1) + " dalam meter: ");

          // Convert data ke hasil
          float hasil = (*data)[i] * 100;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " M", to_string(hasil) + " CM", "(data * 100)", 2);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " m = " << to_string((*result)[indexResult]) << " cm" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan panjang ke-" + to_string(i + 1) + " dalam centimeter: ");

          // Convert data ke hasil
          float hasil = (*data)[i] / 100000;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " CM", to_string(hasil) + " KM", "(data / 100000)", 2);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " cm = " << to_string((*result)[indexResult]) << " km" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan panjang ke-" + to_string(i + 1) + " dalam centimeter: ");

          // Convert data ke hasil
          float hasil = (*data)[i] / 100;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " CM", to_string(hasil) + " M", "(data / 100)", 2);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " cm = " << to_string((*result)[indexResult]) << " m" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 7:
        /**
         * Menampilkan history konversi
         * Parameter 1 yaitu untuk menentukan jenis data
         * 1 = suhu
         * 2 = panjang
         * 3 = berat
         */
        menampilkanHistory(2);
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Konversi berat (gram, kilogram, ons)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiBerat(int *input, int *totalData, vector<float> *data, vector<float> *result) {
  /**
   * Looping akan berjalan selama true (selama program berjalan)
   * Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
   * Untuk kembali ke menu utama cukup dengan break untuk menghentikan looping
   */
  while (true) {
    cout << "--------------------------------" << endl;
    cout << "1) Gram ke Kilogram" << endl;
    cout << "2) Gram ke Ons" << endl;
    cout << "3) Kilogram ke Gram" << endl;
    cout << "4) Kilogram ke Ons" << endl;
    cout << "5) Ons ke Gram" << endl;
    cout << "6) Ons ke Kilogram" << endl;
    cout << "7) Lihat History" << endl;
    cout << "8) Kembali" << endl;
    cout << "--------------------------------" << endl;

    // Mengambil inputan user dan menyimpannya ke variable input dengan pointer
    *input = inputData<int>("Masukkan pilihan: ");

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 8) break;
    else if (*input > 0 && *input < 7) {
      // Mengambil inputan user dan menyimpannya ke variable totalData dengan pointer
      *totalData = inputData<float>("Masukan jumlah data berat yang akan dikonversi2: ");

      // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
      (*totalData > 1) ? data->resize(*totalData) : data->resize(1);
    }

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan konversi berat
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 7 karena pilihan 8 adalah untuk kembali ke menu utama (break)
     */
    switch (*input) {
      case 1:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan berat ke-" + to_string(i + 1) + " dalam gram: ");

          // Convert data ke hasil
          float hasil = (*data)[i] / 1000;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " G", to_string(hasil) + " KG", "(data / 1000)", 3);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " g = " << to_string((*result)[indexResult]) << " kg" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan berat ke-" + to_string(i + 1) + " dalam gram: ");

          // Convert data ke hasil
          float hasil = (*data)[i] / 10;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " G", to_string(hasil) + " ONS", "(data / 10)", 3);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " g = " << to_string((*result)[indexResult]) << " ons" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan berat ke-" + to_string(i + 1) + " dalam kilogram: ");

          // Convert data ke hasil
          float hasil = (*data)[i] * 1000;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " KG", to_string(hasil) + " G", "(data * 1000)", 3);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " kg = " << to_string((*result)[indexResult]) << " g" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan berat ke-" + to_string(i + 1) + " dalam kilogram: ");

          // Convert data ke hasil
          float hasil = (*data)[i] * 10;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " KG", to_string(hasil) + " ONS", "(data * 10)", 3);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " kg = " << to_string((*result)[indexResult]) << " ons" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan berat ke-" + to_string(i + 1) + " dalam ons: ");

          // Convert data ke hasil
          float hasil = (*data)[i] * 100;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " ONS", to_string(hasil) + " G", "(data * 100)", 3);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " ons = " << to_string((*result)[indexResult]) << " g" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData<float>("Masukan berat ke-" + to_string(i + 1) + " dalam ons: ");

          // Convert data ke hasil
          float hasil = (*data)[i] / 10;

          // tidak menggunakan tanda * karena data adalah pointer
          // push_back adalah fungsi untuk menambahkan data ke vector
          // jadi disini kita menambahkan hasil ke vector result
          result->push_back(hasil);

          // Mengirimkan data awal, hasil konversi, dan rumus ke fungsi handleHistory
          handleHistory(to_string((*data)[i]) + " ONS", to_string(hasil) + " KG", "(data / 10)", 3);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << to_string((*data)[i]) << " ons = " << to_string((*result)[indexResult]) << " kg" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 7:
        /**
         * Menampilkan history konversi
         * Parameter 1 yaitu untuk menentukan jenis data
         * 1 = suhu
         * 2 = panjang
         * 3 = berat
         */
        menampilkanHistory(3);
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Menampilkan pesan debug
 * 
 * @param message pesan yang akan ditampilkan ke user - string
 * @param value value yang akan ditampilkan ke user - string
 *
 * @return void
 */
void debug(string message, string value) {
  if (!isDevMode) return;

  cout << "[DEBUG] [" << message << "] : " << value << endl;
}
