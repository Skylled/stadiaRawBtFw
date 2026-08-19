// 600db5a8  FUN_600db5a8  size=108 bytes
// --- callers ---
//   60078da8 FUN_60078da8
// --- callees ---
//   600668dc keys__600668dc
//   600d74ce FUN_600d74ce
//   600669a8 keys__600669a8
//   60066a74 keys__60066a74
//   60066944 keys__60066944


bool FUN_600db5a8(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_600d74ce();
  switch(uVar2) {
  case 1:
    cVar1 = keys__600668dc(param_1,param_2 + 2,0x80);
    uVar2 = 1;
    break;
  case 2:
    cVar1 = keys__60066944(param_1,param_2 + 2);
    uVar2 = 2;
    break;
  case 3:
    cVar1 = keys__600669a8(param_1,param_2 + 2);
    uVar2 = 3;
    break;
  case 4:
    cVar1 = keys__60066a74(param_1,param_2 + 2);
    uVar2 = 4;
    break;
  default:
    return false;
  }
  *param_2 = uVar2;
  if (cVar1 != '\0') {
    *param_2 = 0;
  }
  return cVar1 == '\0' || cVar1 == '\x05';
}


