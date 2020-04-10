## Verwendung
Das Logging kann direkt in die Konsole oder, wenn gewünscht, in eine Datei loggen.

    using logger::Logger;

Nutzen um das Logging einzuschalten.
Anschließend kann wie folgt eine Ausgabe geloggt werden

    Logger::Info("Text");

Es sind die Stufen Info, Warn, Error vorhanden.
Um in eine Datei zu loggen 

    Logger::LogToFile()

aufrufen. Es kann auch der Dateiname angegeben werden.

    Logger::LogFile("filename");

Thread Sicherheit wurde noch nicht berücksichtig.
