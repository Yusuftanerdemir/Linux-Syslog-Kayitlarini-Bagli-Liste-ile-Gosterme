Linux Syslog Kayıtlarını Bağlı Liste ile Gösterme
Bu C programı, Linux sistem günlüklerini (/var/log/syslog) okuyarak bağlı liste (linked list) veri yapısı ile saklar ve ekrana yazdırır. Program, dinamik bellek yönetimi kullanarak sistem günlüklerini verimli bir şekilde işler.

📌 Programın Çalışma Mantığı:

1. Syslog Dosyasını Açma:

Program, doğrudan /var/log/syslog dosyasını açar.
Eğer dosya açılamazsa, bir hata mesajı vererek çıkış yapar.

2.  Bağlı Liste Kullanımı:

Her log satırı, bir düğüm (node) olarak bağlı listeye eklenir.
create_node fonksiyonu, yeni bir düğüm oluşturur.
append_node fonksiyonu, yeni düğümü listenin sonuna ekler.

3. Logları Ekrana Yazdırma:

print_logs fonksiyonu, bağlı listede saklanan tüm syslog kayıtlarını ekrana basar.

4. Bellek Yönetimi:

free_list fonksiyonu, programın sonunda tüm düğümleri temizleyerek bellek sızıntısını (memory leak) önler.

 
  Programın Avantajları:
- Bağlı liste kullanımı sayesinde esnek ve dinamik bir yapı sunar.
- Sistem günlüklerini verimli bir şekilde işler ve belleği optimize kullanır.
- Tamamen otomatik çalışır, kullanıcı girdisine ihtiyaç duymaz.
- Sistem loglarını analiz etmek ve işlemek için temel bir altyapı sağlar.

Bu program, syslog kayıtlarını daha gelişmiş bir şekilde analiz etmek veya filtrelemek için genişletilebilir bir temel oluşturur.