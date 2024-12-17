# Calender
This is a simple calendar program written in C++. It allows users to view the calendar for a specific month and year.

## Usage
1. `git clone https://github.com/Jinghao1209/calendar-cpp.git`
2. `cd calendar-cpp`
3. `bash build.sh`
4. `./main.out -h`

## Help
```bash
<command_name> [options]
```

### Options
| Option                     | Description                         |
|----------------------------|-------------------------------------|
| `-s, --start <start_year>` | Start year                          |
| `-e, --end <end_year>`     | End year                            |
| `-f, --filename <filename>`| Output filename                     |
| `-c, --cover`              | Cover the output file if it exists  |
| `-h, --help`               | Show the help message and exit      |

### Example
To specify a start year, end year, and output file:
```bash
<command_name> -s 2024 -e 2025 -f output.txt
```

This will generate an output file named `output.txt` for the year range 2024 to 2025. Use `-c` to overwrite the file if it already exists.
