cpphttplib = {
	source = path.join(dependencies.basePath, "cpp-httplib"),
}

function cpphttplib.import()
	cpphttplib.includes()
end

function cpphttplib.includes()
	includedirs {
		cpphttplib.source
	}
end

function cpphttplib.project()
	project "cpp-httplib"
		language "C++"

		cpphttplib.includes()

		warnings "Off"
		kind "StaticLib"
end

table.insert(dependencies, cpphttplib)
