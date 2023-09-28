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

	result = read<int64>(base_address + 0xE322218);
	v7 = base_address + 0xE3221D8;
	if (result)
		v7 = result;

	int64 EncryptedData[7];

	for (int i = 0; i < 7; i++)
		EncryptedData[i] = read<__int64>(v7 + (i * 8));
	EncryptedData[0] ^= 0x4CFB2AC8FE274CEBi64;
	EncryptedData[1] ^= 0x4CFB2AC8FE274CEBi64;
	EncryptedData[2] ^= 0x4EFB2AC9FE274CEAi64;
	EncryptedData[3] ^= 0xAF841EB813427C9i64;
	EncryptedData[4] ^= 0xAF841EB813427C9i64;
	EncryptedData[5] ^= 0x4EF841EB813427C9i64;
	EncryptedData[6] ^= 0x4E1DB9AD4C1EF28Bi64;

	ViewPoint.Location = { *(double*)(&EncryptedData[1]),*(double*)(&EncryptedData[0]), *(double*)(&EncryptedData[2]) };
	ViewPoint.Rotation = { *(double*)(&EncryptedData[4]),*(double*)(&EncryptedData[3]), *(double*)(&EncryptedData[5]) };
	ViewPoint.FieldOfView = *(float*)(&EncryptedData[6]);

	return ViewPoint;

}
