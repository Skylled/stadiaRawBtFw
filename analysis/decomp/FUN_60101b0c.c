// 60101b0c  FUN_60101b0c  size=64 bytes
// --- callers ---
//   600daddc FUN_600daddc
//   60076b78 FUN_60076b78
//   600d6d96 FUN_600d6d96
//   600d37ce FUN_600d37ce
//   600834a4 parser__600834a4
//   600666f0 keys__600666f0
//   600d37fe FUN_600d37fe
//   60058b68 FUN_60058b68
//   60078340 firmware_image_upload__60078340
//   600d4d2e FUN_600d4d2e
//   600d521e FUN_600d521e
//   600d3ac4 FUN_600d3ac4
//   600d38c8 FUN_600d38c8
//   60058f58 FUN_60058f58
//   600d3938 FUN_600d3938
// --- callees ---
//   60050c18 FUN_60050c18


void FUN_60101b0c(int param_1,int param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  
  if (-1 < param_2) {
    FUN_60050c18();
    return;
  }
  uVar3 = param_4;
  if (param_4 != 0) {
    uVar3 = param_4 - 1;
  }
  iVar1 = FUN_60050c18(-param_1,-param_2 - (uint)(param_1 != 0),param_3 + 1,uVar3);
  if (iVar1 + 1U < param_4) {
    uVar2 = 0x2d;
  }
  else {
    if (param_4 == 0) {
      return;
    }
    uVar2 = 0;
  }
  *param_3 = uVar2;
  return;
}


