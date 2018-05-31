echo aaaaa
powershell -ExecutionPolicy ByPass -File preBuild.ps1 > dummy.txt
type dummy.txt
echo bbbbb
