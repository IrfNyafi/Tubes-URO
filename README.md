# Tugas Besar URO Divisi Programming Kelompok 6

<p>&nbsp;</p>

## Kontributor Program Permainan Kapal
### Irfan Yafi Pranoto (16922250)
### Arvyno Pranata Limahardja (19622125)
### Chelvadinda (19622276)
### Zulfan Andria Putranto (16522153)

<p>&nbsp;</p>

## Daftar Isi
### 1. Deskripsi Program
### 2. Panduan Penggunaan Program

<p>&nbsp;</p>

### 1. Deskripsi Program 
Program ini merupakan sebuah program permainan kapal, yang pada prinsipnya, user memiliki objektif untuk mempertahankan kapalnya dan memenangkan pertandingan dengan mengalahkan kapal musuh lainnya yang merupakan bot. Program ini dibuat untuk menuntaskan tugas besar yang diperintahkan oleh KRU URO Divisi Programming untuk mempersiapkan segenap CAKRU untuk memiliki fondasi pengetahuan dan kemampuan teknis yang cukup sebelum bertanding di kompetisi robot yang sesungguhnya.  

Terdapat beberapa fitur yang ditanamkan dalam program ini, sebagai berikut:
1. Program menampilkan posisi kapal user dalam bentuk ## dan posisi kapal musuh (bot) dalam bentuk MX (bisa berupa M1, M2, atau M3 karena limitasi kapal musuh sebanyak tiga buah).
2. Program dapat berlayar di dalam sebuah grid yang terdiri atas 15 alfabet (huruf A sampai dengan huruf O) dan 20 angka (angka 1 sampai dengan angka 20).
3. Program dapat menerima input user berupa AX dengan A merupakan huruf yang terbatas pada huruf A sampai dengan huruf O dan X merupakan angka yang terbatas pada angka 1 sampai dengan angka 20.
4. Kapal user dan kapal musuh pada program memiliki atribut health dan program menampilkan health. Kapal user memiliki jumlah health yang lebih banyak ketimbang kapal musuh untuk menyeimbangkan tingkat kesulitan dalam game (dengan jumlah kapal musuh yang lebih banyak).
5. Kapal user dan kapal musuh pada program dapat menyerang lawan. Untuk besar damage kapal user diatur lebih besar ketimbang kapal musuh untuk menyeimbangkan tingkat kesulitan game (dengan jumlah kapal musuh yang lebih banyak).
6. Kapal user dan kapal musuh memiliki jarak tembak maksimum. Untuk besar radius serang kapal user lebih besar daripada kapal musuh untuk menyeimbangkan tingkat kesulitan game (dengan jumlah kapal musuh yang lebih banyak).
7. Program akan secara otomatis menutup game dengan pesan jumlah kapal musuh yang berhasil dikalahkan jika:

    a. Kapal user berhasil menumbangkan seluruh kapal musuh yang ditunjukkan dengan indikator health setiap kapal musuh mencapai nol
  
    b. Kapal user dikalahkan oleh satu/lebih kapal musuh yang ditunjukkan dengan indikator health setiap kapal musuh mencapai nol
8. Program akan menempatkan obstacle berupa batu yang ditampilkan dalam bentuk * untuk menambahkan dinamika dalam game. 
9. Kapal user dapat bergerak sebanyak dua langkah. Sedangkan, kapal musuh hanya dapat bergerak sebanyak satu langkah. Aksi yang termasuk dalam perhitungan langkah, ialah bergerak ke suatu koordinat atau menembak. Untuk pergerakan kapal menuju koordinat tertentu, dibatasi pada area gerak berupa persegi dengan besar 3 x 3 di sekitar kapal user/musuh. Untuk menembak, dibedakan sesuai jenis kapal. Kapal user dibatasi pada area tembak berupa persegi dengan besar () x () di sekitar kapal user. Sementara, kapal musuh dibatasi pada area tembak berupa persegi dengan besar () x () di sekitar kapal musuh.
10. Jika user melakukan input data yang tidak sesuai, seperti:

    a. Koordinat pergerakan kapal menuju ke luar grid (atau peta)
    
    b. Tembakan ke arah salah satu kapal musuh yang melebihi jarak maksimum tembak
    
    c. Bergerak atau menembak ke arah batu sebagai obstacle
    
    d. Bergerak menabrak kapal musuh
        
    Maka, program akan mengeluarkan pesan error berupa “()”.
    
<p>&nbsp;</p>

### 2. Panduan Penggunaan Program
1. Program akan meminta perintah untuk bergerak atau menembak. Jika memilih untuk bergerak, maka user dapat memasukkan posisi yang diinginkan dengan menuliskan AX dengan A merupakan huruf yang terbatas pada huruf A sampai dengan huruf O dan X merupakan angka yang terbatas pada angka 1 sampai dengan angka 20. Jika memilih untuk menembak, maka user dapat memasukkan identitas kapal musuh yang ingin ditembak. Jika tidak ingin bergerak atau menembak, cukup input posisi kapal user saat itu.
2. Limitasi yang dibuat pada program perlu dipatuhi oleh user, seperti:

    a. Terdapat batas maksimum gerak kapal user dengan area gerak berupa persegi dengan besar 3 x 3 di sekitar kapal user/musuh
    
    b. Terdapat batas maksimum jarak tembak dengan area tembak berupa persegi dengan besar () x () di sekitar kapal user
    
    c. Kapal tidak bisa bergerak maupun menembak ke arah grid yang ditempati oleh batu sebagai obstacle
    
    d. Kapal tidak bisa bergerak ke arah grid yang ditempati oleh salah satu kapal musuh
