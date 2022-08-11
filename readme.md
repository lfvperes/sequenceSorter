# Sequence Sorter

This program recieves a .CSV file as input, containing unsorted sequences on each line. It generates as output a .CSV file containing the same sequences, sorted.
Both files need to be specified as command line arguments.

To run Sequence Sorter through a CLI after compilation:
```
>> ./sequenceSorter <input-file-name>.csv <output-file-name>.csv
```
Where `<input-file-name>.csv` and `<output-file-name>.csv` are the names for the file where the unsorted sequences are stored and the file to store the sorted sequences, respectively. Example:
```
>> make all
>> ./sequenceSorter inputFloatSequences.csv outputFloatSequences.csv
```

