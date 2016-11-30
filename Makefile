all: main

profile: main
	perf record ./main

clean:
	rm -f main
	rm -f perf.data perf.data.old

.PHONY: clean all profile
