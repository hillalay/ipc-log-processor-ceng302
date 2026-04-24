# docs

Bu klasor proje dokumantasyonu icindir.

## Burada Neler Tutulmali?

- Mimari kararlar (pipe ve shm tasarimi)
- Protokol/aciklama notlari (ureticiden tuketiciye veri akisi)
- Senkronizasyon yaklasimi (mutex, semaphore, kritik bolgeler)
- Hata yonetimi stratejisi
- Bilinen kisitlar ve edge-case notlari

## Onerilen Dokuman Basliklari

- `architecture.md`
- `ipc-design.md`
- `thread-model.md`
- `test-protocol.md`
- `known-issues.md`

## Bu Repoda Eklenen Dokumanlar

- `architecture.md`: Bilesenler ve ust seviye akis
- `ipc-design.md`: Pipe/SHM teknik tasarim notlari
- `thread-model.md`: Thread ve senkronizasyon beklentileri
- `test-protocol.md`: Test calistirma protokolu ve script sozlesmesi
- `known-issues.md`: Problem takip sablonu

## Script-First Kurali

Bu projede test scripti degistirilmeyecek sekilde ele alinmaktadir.
Bu nedenle kod ve test varliklari scriptin bekledigi dosya adlari/konumlariyla uyumlu olmalidir.

## Yazim Kurali

- Teknik kararlar gerekceli yazilsin.
- Varsayimlar net belirtilsin.
- Kod parcasi veriliyorsa kisa ve test edilebilir olsun.
