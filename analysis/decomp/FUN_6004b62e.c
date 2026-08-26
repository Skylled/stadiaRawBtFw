// 6004b62e  FUN_6004b62e  size=374 bytes
// --- callers ---
//   6004b7b4 FUN_6004b7b4
//   6004b7f2 FUN_6004b7f2
// --- callees ---
//   6004b5c0 FUN_6004b5c0


void FUN_6004b62e(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_50;
  uint uStack_4c;
  uint local_48;
  uint uStack_44;
  uint local_40;
  uint uStack_3c;
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  uint local_28;
  uint uStack_24;
  
  FUN_6004b5c0(&local_50,&local_48,*param_1,param_1[1],param_2[2],param_2[3]);
  FUN_6004b5c0(&local_40,&local_38,param_1[2],param_1[3],*param_2,param_2[1]);
  FUN_6004b5c0(&local_30,&local_28,param_1[2] ^ *param_1,param_1[3] ^ param_1[1],
               param_2[2] ^ *param_2,param_2[3] ^ param_2[1]);
  uVar1 = local_50 ^ local_40 ^ local_48 ^ local_30;
  uVar2 = uStack_4c ^ uStack_3c ^ uStack_44 ^ uStack_2c;
  uVar3 = uVar2 ^ local_50 << 0x1f ^ local_50 << 0x1e ^ local_50 << 0x19;
  *param_1 = (local_50 >> 2 | uStack_4c << 0x1e) ^
             local_50 ^ local_40 ^ local_48 ^ local_38 ^ local_28 ^
             ((uint)((uStack_4c & 1) != 0) << 0x1f | local_50 >> 1) ^
             (local_50 >> 7 | uStack_4c << 0x19);
  param_1[1] = uVar1 << 0x1e ^
               uStack_4c >> 2 ^
               uStack_4c ^ uStack_3c ^ uStack_44 ^ uStack_34 ^ uStack_24 ^ uStack_4c >> 1 ^
               uStack_4c >> 7 ^ uVar1 << 0x1f ^ uVar1 << 0x19;
  param_1[2] = uVar1 ^ local_38 ^ ((uint)((uVar3 & 1) != 0) << 0x1f | uVar1 >> 1) ^
               (uVar1 >> 2 | uVar2 << 0x1e) ^ (uVar1 >> 7 | uVar2 << 0x19);
  param_1[3] = uVar3 ^ uStack_34 ^ uVar3 >> 1 ^ uVar3 >> 2 ^ uVar3 >> 7;
  return;
}


