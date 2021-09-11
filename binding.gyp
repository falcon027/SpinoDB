{
	"targets": [
	{
		"target_name": "spinodb",
			"sources": [ 
				"cppsrc/main.cpp",
			"cppsrc/SpinoWrapper.cpp",
			"cppsrc/SpinoDB.cpp",
			"cppsrc/QueryParser.cpp",
			"cppsrc/QueryExecutor.cpp",
			"cppsrc/hopman_fast.cpp"
			],
		"cflags!": [ "-fno-exceptions" ],
		"cflags_cc!": [ "-fno-exceptions" ],
		"cflags": [ "-O3" ],
		"cflags_cc": ["-O3"]
	}
	]
}
