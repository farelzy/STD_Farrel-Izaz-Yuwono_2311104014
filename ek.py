import random

# Inisialisasi saldo awal
saldo = 0
biaya_input = 0  # Biaya yang diatur di menu 2
counter_spin = 0  # Menghitung jumlah spin

# Faktor pengali untuk minus
MINUS_FACTORS = {1000: 10, 2000: 1, 3000: 1, 10000: 1, 50000: 1}

def tambah_saldo(saldo):
    """Fungsi untuk menambah saldo."""
    try:
        jumlah = int(input("Masukkan jumlah saldo yang ingin ditambahkan: "))
        if jumlah <= 0:
            print("Jumlah saldo harus lebih besar dari 0.")
            return saldo
        saldo += jumlah
        print(f"Saldo berhasil ditambahkan. Saldo saat ini: {saldo}")
    except ValueError:
        print("Input tidak valid. Masukkan angka.")
    return saldo

def set_biaya():
    """Fungsi untuk menentukan biaya spin."""
    try:
        biaya = int(input("Masukkan biaya: "))
        if biaya not in MINUS_FACTORS:
            print("Input tidak valid.")
            return set_biaya()
        print(f"Biaya telah diatur: {biaya}")
        return biaya
    except ValueError:
        print("Input tidak valid. Masukkan angka.")
        return set_biaya()

def spin(saldo, counter_spin, biaya_input):
    """Fungsi untuk melakukan spin."""
    if saldo <= 0:
        print("Saldo Anda tidak cukup untuk melakukan spin!")
        return saldo, counter_spin

    # Hitung minus dan peluang menang
    minus = int(biaya_input * MINUS_FACTORS[biaya_input])
    peluang_menang = 0.3  # 30% peluang untuk menang

    # Tentukan hasil spin (menang atau kalah)
    if random.random() < peluang_menang:  # Jika menang
        hasil_spin = random.randint(2, 5) * biaya_input  # Hadiah berupa kelipatan biaya
        print(f"Selamat! Anda menang. Hadiah: {hasil_spin}")
    else:  # Jika kalah
        hasil_spin = -minus
        print(f"Anda melakukan spin... Minus yang dikenakan: {hasil_spin}")

    # Update saldo
    saldo += hasil_spin
    saldo = max(saldo, 0)  # Saldo tidak boleh minus
    print(f"Saldo Anda setelah spin: {saldo}")

    # Increment jumlah spin
    counter_spin += 1

    # Bonus setelah 5 spin
    if counter_spin == 5:
        bonus = biaya_input * 30
        saldo += bonus
        print(f"\nSelamat! Anda telah melakukan 5 spin. Bonus diberikan: {bonus}")
        print(f"Saldo Anda sekarang: {saldo}\n")
        counter_spin = 0  # Reset counter spin

    return saldo, counter_spin

def show_saldo(saldo):
    """Fungsi untuk menampilkan saldo saat ini."""
    print(f"\nSaldo Anda saat ini: {saldo}\n")

def menu():
    """Fungsi untuk menampilkan menu utama."""
    print("\n=== MENU ===")
    print("1. Tambah Saldo")
    print("2. Set Biaya Main")
    print("3. Spin")
    print("4. Show Saldo")
    print("5. Keluar")

# Program utama
print("=== Selamat Datang di Permainan ===")
while True:
    menu()
    pilihan = input("Masukkan pilihan Anda (1/2/3/4/5): ")
    
    if pilihan == "1":
        saldo = tambah_saldo(saldo)
    elif pilihan == "2":
        biaya_input = set_biaya()
    elif pilihan == "3":
        if biaya_input == 0:
            print("Silakan atur biaya terlebih dahulu!")
        else:
            saldo, counter_spin = spin(saldo, counter_spin, biaya_input)
    elif pilihan == "4":
        show_saldo(saldo)
    elif pilihan == "5":
        print("Terima kasih telah bermain! Saldo akhir Anda:", saldo)
        break
    else:
        print("Pilihan tidak valid. Silakan coba lagi.")