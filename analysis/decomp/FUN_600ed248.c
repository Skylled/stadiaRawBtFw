// 600ed248  FUN_600ed248  size=30 bytes
// --- callers ---
// --- callees ---
//   600ecfae FUN_600ecfae
//   600ecf0a FUN_600ecf0a


void FUN_600ed248(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2;
  uVar1 = FUN_600ecfae();
  if ((int)uVar1 != 0) {
    FUN_600ecf0a(*param_1,(int)((ulonglong)uVar1 >> 0x20),param_2,0,4,uVar2,param_3);
  }
  return;
}


