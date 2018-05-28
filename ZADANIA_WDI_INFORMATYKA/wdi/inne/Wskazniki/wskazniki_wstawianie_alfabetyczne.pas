program czytanie_z_pliku;

type
    wskaznik_elementu = ^element;
    element = record
              wartosc : integer;
              next : wskaznik_elementu;   {next : ^element}
              end;

var
    p : wskaznik_elementu;   {p : ^element}

{wstawianie elementu na poczatku lancucha odsylaczowego}
procedure wstaw_na_poczatku(var poczatek_listy : wskaznik_elementu; nowa_wartosc : integer);
var
    e : wskaznik_elementu;
begin
    New(e);                     {utworz nowa zmienna typu element na stercie(heap)}
    e^.wartosc := nowa_wartosc; {wpisujemy wartosc do nowej zmiennej}
    e^.next := poczatek_listy;  {wpisujemy wskaznik do pierwszego elementu istniejacej listy(moze byc nil)}
    poczatek_listy := e;        {wskaznik p wskazuje na nowo utworzony element}
end;

{wstawianie z jednoczesnym sortowaniem przez proste wstawianie}
procedure wstaw_alfabetycznie(var poczatek_listy : wskaznik_elementu; nowa_wartosc : integer);
var
    aktualny_element, wstawiany_element : wskaznik_elementu;
begin
    New(wstawiany_element);
    wstawiany_element^.wartosc := nowa_wartosc;
    if poczatek_listy = nil then
    begin
        wstawiany_element^.next := nil;
        poczatek_listy := wstawiany_element;
    end
    else
    begin
        aktualny_element := poczatek_listy;
        while (aktualny_element^.wartosc < nowa_wartosc) and (aktualny_element^.next <> nil) do
            aktualny_element := aktualny_element^.next;
        {dopisujemy zawsze ZA znalezionym elementem}
        wstawiany_element^.next := aktualny_element^.next;
        aktualny_element^.next := wstawiany_element;
        if nowa_wartosc <= aktualny_element^.wartosc then
        begin
            {zamieniamy WARTOSCI miejscami!!!}
            wstawiany_element^.wartosc := aktualny_element^.wartosc;
            aktualny_element^.wartosc := nowa_wartosc;
        end;
    end;
end;



{wstawianie elementu na koncu lancucha odsylaczowego}
procedure wstaw_na_koncu(var poczatek_listy: wskaznik_elementu; nowa_wartosc : integer);
var
    nowy_element : wskaznik_elementu;
    koniec_listy : wskaznik_elementu;
begin
    New(nowy_element);
    nowy_element^.wartosc := nowa_wartosc;
    nowy_element^.next := nil;
    if poczatek_listy = nil then
        poczatek_listy := nowy_element
    else
    begin
        koniec_listy := poczatek_listy;
        while koniec_listy^.next <> nil do        {z petli wychodzimy ze wskaznikiem do ostatniego elementu}
            koniec_listy := koniec_listy^.next;
        koniec_listy^.next := nowy_element;
    end
end;


procedure wypisz_liste(poczatek_listy : wskaznik_elementu);
begin
    while poczatek_listy <> nil do
    begin
        writeln(poczatek_listy^.wartosc);
        poczatek_listy := poczatek_listy^.next;
    end;
end;

{zwolnienie pamieci zajmowanej przez elementy lancucha odsylaczowego}
procedure zwolnij_liste(var poczatek_listy : wskaznik_elementu);
var
    nastepny : wskaznik_elementu;
begin
    while poczatek_listy <> nil do
    begin
        nastepny := poczatek_listy^.next;   {zapamietanie adresu do nastepnego elementu}
        Dispose(poczatek_listy);            {zwolnienie pamieci}
        poczatek_listy := nastepny;         {adres nastepnego elementu}
    end;
end;

procedure czytaj_liste_z_pliku(var poczatek_listy : wskaznik_elementu; nazwa_pliku : string);
var
    plik : text;
    n : integer;
begin
    assign(plik, nazwa_pliku);   {zwiazanie zmiennej plikowej z plikiem}
    reset(plik);                {otwarcie pliku do odczytu, rewrite() do zapisu}
    {czytanie z pliku i tworzenie lancucha odsylaczowego}
    while not eof(plik) do
    begin
        read(plik, n);
        wstaw_alfabetycznie(poczatek_listy, n);
    end;
    close(plik);                 {zamkniecie pliku}
end;


function istnieje(poczatek_listy : wskaznik_elementu; wartosc : integer): boolean;
begin
    istnieje := false;
    while (poczatek_listy <> nil) and (not istnieje) do
    begin
        if poczatek_listy^.wartosc = wartosc then
            istnieje := true
        else
            poczatek_listy := poczatek_listy^.next
    end;
end;


begin
    p := nil;        {nie ma listy - pusty wskaznik}
    czytaj_liste_z_pliku(p, '/home/piotr/Desktop/pascal/sandra/liczby.txt');
    wypisz_liste(p);
    zwolnij_liste(p);
end.

