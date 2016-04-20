## Map Creator

Program tworzący mape podobną do mapy z gry Minecraft

![Map Creator Output](output.png)

### Kompilacja
Program należy skompilować podaną komendą:
```
g++ -std=c++11 *.cpp
```

### Plik wejściowy
Plik wejściowy to ```input-map.csv```, nie jest on możliwy do zmiany przez podanie argumentów to programu.


Jest on zrobiony na zasadzie pliku ```csv```.
```
wysokość:typ:tekstura;wysokość:typ:tekstura;...
wysokość:typ:tekstura;wysokość:typ:tekstura;...
wysokość:typ:tekstura;wysokość:typ:tekstura;...
...
```

### Plik wyjściowy
Jest to standardowy plik ```svg``` nazwany ```output-map.svg```, który jest zgodnym ze standardem [http://www.w3.org/2000/svg](http://www.w3.org/2000/svg)
