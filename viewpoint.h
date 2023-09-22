struct CamewaDescwipsion
{
	Vector3 Location;
	Vector3 Rotation;
	float FieldOfView;
};

CamewaDescwipsion GetViewPoint()
{
	CamewaDescwipsion ViewPoint;
	__int64 result; // rax
	__int64 v7; // rcx

	result = read<__int64>(base_address + 0xE2CED18);
	v7 = base_address + 0xE2CECD8;
	if (result)
		v7 = result;

	__int64 EncryptedData[7];
	for (int i = 0; i < 7; i++)
		EncryptedData[i] = read<__int64>(v7 + (i * 0x8));
	EncryptedData[0] ^= 0x4CF1F15DFE2D977Fi64;
	EncryptedData[1] ^= 0x4CF1F15DFE2D977Fi64;
	EncryptedData[2] ^= 0x4EF1F15DFE2D977Fi64;
	EncryptedData[3] ^= 0xAF29A7F813EFC5Ci64;
	EncryptedData[4] ^= 0xAF29A7F813EFC5Ci64;
	EncryptedData[5] ^= 0x4EF29A7E813EFC5Di64;
	EncryptedData[6] ^= 0x4E1772384C14291Fi64;

	ViewPoint.Location = {
		*(double*)(&EncryptedData[1]),
		*(double*)(&EncryptedData[0]),
		*(double*)(&EncryptedData[2])
	};
	ViewPoint.Rotation = {
		*(double*)(&EncryptedData[4]),
		*(double*)(&EncryptedData[3]),
		*(double*)(&EncryptedData[5])
	};
	ViewPoint.FieldOfView = *(float*)(&EncryptedData[6]);

	return ViewPoint;
}