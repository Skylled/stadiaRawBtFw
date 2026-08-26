// 600d866a  FUN_600d866a  size=80 bytes
// --- callers ---
//   600d8722 FUN_600d8722
//   600d86ba FUN_600d86ba
//   60068cb4 battery_gauge_bq2742X__60068cb4
// --- callees ---
//   600d3618 FUN_600d3618
//   600d8636 FUN_600d8636
//   6013cef8 thunk_EXT_FUN_0000737c


uint FUN_600d866a(undefined4 param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_24;
  uint uStack_20;
  
  uStack_24 = param_2 & 0xffff;
  uStack_20 = param_3;
  iVar1 = FUN_600d3618();
  while( true ) {
    uVar2 = FUN_600d8636(param_1,0,(int)&uStack_24 + 2);
    if ((uVar2 & 0xff) != 0) {
      return uVar2;
    }
    thunk_EXT_FUN_0000737c(10);
    if ((param_2 & uStack_24 >> 0x10) == param_3) break;
    uVar2 = FUN_600d3618();
    if ((uint)(param_4 + iVar1) < uVar2) {
      return 4;
    }
  }
  return 0;
}


