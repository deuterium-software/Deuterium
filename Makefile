CC=gcc

all: no-d-file

no-d-file:
	@echo Compiling...
	@$(CC) versions/unix/dt.c -o dist/dt
	@printf "Finished compiling\n\n"

	@rm dist -r
	@mkdir dist

	@echo Copying to //usr/bin...
	@sudo cp dist/dt //usr/bin/
	@printf "Finished copying\n\n"

with-d-file:
	@printf "D FILE SPECIFIED \n"

	@rm dist -r
	@mkdir dist

	@echo Compiling...
	@$(CC) versions/unix/dt.c -o dist/dt
	@$(CC) versions/unix/dt.c -o dist/d
	@printf "Finished compiling\n\n"

	@echo Copying to //usr/bin...
	@sudo cp dist/dt //usr/bin/
	@sudo cp dist/d //usr/bin/
	@printf "Finished copying\n\n"

uninstall:
	@echo Removing dt...
	@sudo rm /usr/bin/dt
	@echo Removing d...
	@sudo rm /usr/bin/d
