# __Imitator Nedir?__ #
    Imitator mouse hareketlerimizi kaydedip tekrardan aynı şekilde taklit edebilmesini sağlayan bir Windows uygulamasıdır. Imitator'un
    en güzel yanı uygulama çalışır haldeyken başka uygulama ile uğraşıyor olsak dahi klavyemizin tuşlarına duyarlı olmasıdır. Yani başka 
    herhangi bir uygulama içinde işlem yaparken ALT+1 tuşlarına basarak mouse hareketlerimizi kaydetmemizi sağlayabilir veya ALT+2 
    tuşlarına basarak kaydımızı anında çalıştırabilir. ALT+3 tuşuyla da uygulamaya tıklama zorunluluğu olmadan anında kapatabiliriz.
    Kaydımızı bitirmek istediğimiz anda uygulamaya tekrar dönme zorunluluğu olmadan ALT GR tuşuna basarak kaydı tamamlayabilir veya 
    hareketlerimizi taklit ederken durdurabilmek için yine ALT GR tuşuna basabiliriz.
# __Gereklilikler__ #
    Windows İşletim Sistemi (Windows 10 haricinde denemedim ancak büyük ihtimalle diğer sürümlerde de çalışacaktır.)
    CMake (min. ver. 3.16.3)
    MinGW veya MSVC compiler
# Build İşlemleri #
    Build işlemleri için Visual Studio veya VS Code kullanılması tavsiye edilir.
## __Visual Studio__ ##
    Visual Studio kullanılırken MSVC kullanmanız tavsiye edilir.
    CMakeSettings.json dosyası açılır.
    msvc_x64_x64 harici bir compiler kullanılacaksa uygun şekilde değiştirilir.
    Proje klasörü Visual Studio ile açılır.
    CMake ayarları otomatikmen başlangıçta yapılacaktır.
    Çözüm gezgini üzerinden herhangi .cpp uzantili bir dosya seçilerek (main.cpp önerilir) compile edilir.
    Compile işlemi tamamlandıktan sonra proje klasörü içerisindeki /bin klasöründe Imitator.exe dosyasına ulaşabilirsiniz.
## __VS Code__ ##
    VS Code kullanılıyorsa MinGW kullanmanız tavsiye edilir. Ayarlar MinGW'ye göre yapılmıştır.
    .vscode klasörü içerisindeki launch.json dosyası açılır.
    "miDebuggerPath" parametresinin değeri MinGW derleyicinizin bin klasörü içerisindeki gdb.exe dosyasını gösterecek şekilde ayarlanır.
    .vscode klasörü içerisindeki tasks.json dosyası açılır.
    47. satırda bulunan "command": "mingw32-make", kısmındaki mingw32-make değeri yine MinGW derleyicinizin bin klasörü içerisinde
    kontrol etmeniz gerekir. Bu derleyicinin bazı sürümlerinde make.exe olarak yer alırken bazılarında ise mingw32-make.exe olarak
    yer alır. Bende mingw32-make.exe idi. Burada önemli nokta .exe uzantısını parametremize eklemeyeceğiz. Uygun şekilde düzenleyin.
    Buraya kadar işlemleri hallettiysek VS Code'dan open folder diyerek klasörümüzü seçiyoruz.
    Terminal'den Run Build Task diyoruz.
    Build ettikten sonra Run kısmından Start Debugging diyerek işlemin tamamlanmasını bekliyoruz.
    İşlem tamamlandıktan sonra proje klasörümüzdeki /bin klasörün üzerinden Imitator.exe dosyamıza ulaşabiliriz.
# __Hints__ #
    İşlemcimizin hızına bağlı olarak Imitator'un yaptığı hareket hızı artıp azalabilir. Kayıt yaparken ve yaptığımız kaydı 
    gerçekleştirirken geçirilen süreleri hesaplayabilmek için chrono kütüphanesinden bazı fonksiyonlar kullandım. Fonksiyonun çağrıldığı
    andan fonksiyonun tamamlandığı ana kadar olan süreyi hesaplıyorlar. File.cpp üzerinde ilgili fonksiyonları görebilirsiniz.
    Hareket hızını kontrol altına alabilmek için File classımızın içine sleepTime değişkenini tanımladım. sleepTime için 30 değerini
    kullandığımda yani her 30 milisaniyede bir işlem yapılmasını istediğimde yaklaşık olarak maksimum ±%3 sapma süresi tespit edebildim.
    Bu değer gayet iyi ancak sleepTime artırılması bazı sorunlara da yol açıyor. Örneğin bazı noktaları atlayarak geçebilir veya mouse
    tuşlarına basıp çektiğiniz süreler arasında minik oynamalar olmasından kaynaklı ani yapılan tıklama işlemlerindede hatalara yol
    açabiliyor. Bu nedenle kullanım esnasında işlem süreleri mümkünse incelenerek işlemcinize bağlı olarak en uygun sleepTime eklenmesi 
    kullanıcı deneyimi için iyi olur görüşündeyim. Default olarak sleepTime değerini 0 verdim ancak File constructorundan kolaylıkla bu 
    değeri değiştirebilirsiniz.
    Bunun dışında olası sorunlar veya kontrol amaçlı bazı satırları yorum satırına aldım isterseniz silebilirsiniz lakin geliştirme
    yapılmak istenirse yardımcı olacaklarını düşünüyorum.
# __Projenin Amacı__ #
    Bu projeyi yapmamdaki amaç ilerleyen dönemler için bir kilometre taşı olmasıdır. Elde edebileceğim bilgileri daha farklı işler için
    kullanmayı hedefliyorum. Sonuçta her ne kadar gereksiz bir proje gibi görünse de önemli olan şey buradan kendime ne katabildiğimdir.
    Teşekkür ederim.
    Seyit Cem Yılmaz
    
    
