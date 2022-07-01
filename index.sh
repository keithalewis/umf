#!/usr/bin/bash
cat <<EoF
<html>
<head>
<title>Unified Mathematical Finance</title>
<link rel="stylesheet" href="math.css" />
</head>
<body>
<h1>Unified Mathematical Finance</h1>
EoF

for i in "$@"
do
	TITLE=$(grep '^title:' $i.md | sed 's/^title:\s*//')
	echo "<p><a href=\"$i.html\">$TITLE</a></p>"
done

cat <<EoF
</body>
</html>
EoF
