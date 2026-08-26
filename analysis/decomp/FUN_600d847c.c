// 600d847c  FUN_600d847c  size=82 bytes
// --- callers ---
//   600d8722 FUN_600d8722
//   600d8778 FUN_600d8778
// --- callees ---
//   600d4330 FUN_600d4330
//   600d3618 FUN_600d3618
//   6013cef8 thunk_EXT_FUN_0000737c


char FUN_600d847c(undefined4 param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uStack_24;
  uint uStack_20;
  
  uStack_24 = param_2 & 0xffff;
  uVar4 = param_1;
  uStack_20 = param_3;
  iVar2 = FUN_600d3618();
  while( true ) {
    cVar1 = FUN_600d4330(param_1,6,(int)&uStack_24 + 2,200,uVar4);
    if (cVar1 != '\0') {
      return cVar1;
    }
    thunk_EXT_FUN_0000737c(10);
    if ((param_2 & uStack_24 >> 0x10) == param_3) break;
    uVar3 = FUN_600d3618();
    if (iVar2 + 4000U < uVar3) {
      return '\x04';
    }
  }
  return '\0';
}


