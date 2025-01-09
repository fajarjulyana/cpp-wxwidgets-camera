# Aplikasi Kamera dengan wxWidgets dan OpenCV

Proyek ini adalah aplikasi kamera sederhana yang dibangun menggunakan wxWidgets dan OpenCV. Aplikasi ini menangkap video langsung dari kamera default dan menampilkannya di jendela wxWidgets. Tampilan kamera diperbarui secara terus-menerus dengan sekitar 33 frame per detik.

## Fitur
- Menampilkan tampilan kamera secara real-time dalam frame wxWidgets.
- Menggunakan OpenCV untuk menangkap frame video.
- UI sederhana dan responsif yang dibangun dengan wxWidgets.

## Prasyarat
Sebelum membangun aplikasi, pastikan bahwa dependensi berikut terinstal di sistem Anda:

1. **wxWidgets**: Sebuah pustaka C++ untuk membuat antarmuka pengguna grafis.
2. **OpenCV**: Sebuah pustaka powerful untuk tugas penglihatan komputer.

### Instalasi

#### 1. Instal wxWidgets
Ikuti panduan instalasi untuk wxWidgets berdasarkan sistem operasi Anda:

- [Panduan Instalasi wxWidgets](https://wxwidgets.org/downloads/)

#### 2. Instal OpenCV
Ikuti petunjuk instalasi OpenCV:

- [Panduan Instalasi OpenCV](https://docs.opencv.org/master/d2/de6/tutorial_py_setup_in_windows.html)

## Membangun Proyek

1. Klon repositori atau unduh kode sumber.
2. Buka proyek di IDE pilihan Anda (misalnya, Code::Blocks, Visual Studio).
3. Pastikan pustaka wxWidgets dan OpenCV sudah benar-benar dihubungkan di konfigurasi build IDE Anda.
4. Bangun dan jalankan proyek.

## Penjelasan Kode

- **CameraFrame**: Ini adalah frame utama dari aplikasi yang berisi bitmap statis (`cameraView`) untuk menampilkan feed kamera.
- **OnCameraUpdate**: Fungsi ini dipanggil oleh timer setiap 30ms untuk menangkap frame baru dari kamera dan memperbarui `cameraView`.
- **CameraApp**: Ini adalah kelas aplikasi wxWidgets yang menginisialisasi dan menampilkan jendela utama.

## Penggunaan

1. Jalankan aplikasi.
2. Feed kamera akan ditampilkan di dalam jendela.
3. Jika kamera tidak tersedia, pesan kesalahan akan ditampilkan.

## Pemecahan Masalah

- Jika Anda mengalami masalah dengan akses kamera, pastikan kamera Anda terhubung dan dikenali dengan benar oleh sistem.
- Pastikan wxWidgets dan OpenCV telah terinstal dan terhubung dengan benar ke proyek.

## Lisensi

Proyek ini dilisensikan di bawah Lisensi MIT - lihat file [LICENSE](LICENSE) untuk detailnya.

