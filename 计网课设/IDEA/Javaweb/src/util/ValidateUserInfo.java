package util;

public class ValidateUserInfo {
    private static final String REGEX_EMAIL = "^([a-z0-9A-Z]+[-|\\.]?)+[a-z0-9A-Z]@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\\.)+[a-zA-Z]{2,}$";

    public ValidateUserInfo() {
    }

    public static String validate(String id, String pass, String name, String email, String sex, String intro) {
        StringBuilder sb = new StringBuilder();
        String temp;
        if ((temp = validateID(id)) != null) {
            sb.append(temp + "；");
        }

        if ((temp = validatePassword(pass)) != null) {
            sb.append(temp + "；");
        }

        if ((temp = validateName(name)) != null) {
            sb.append(temp + "；");
        }

        if ((temp = validateEmail(email)) != null) {
            sb.append(temp + "；");
        }

        if ((temp = validateSex(sex)) != null) {
            sb.append(temp + "；");
        }

        if ((temp = validateIntro(intro)) != null) {
            sb.append(temp + "；");
        }

        String result = sb.toString();
        return "".equals(result) ? null : result;
    }

    public static String validateID(String id) {
        if (id != null && !"".equals(id)) {
            if (id.length() > 10) {
                return "用户名为1到10个字符";
            } else {
                for(int i = 0; i < id.length(); ++i) {
                    char c = id.charAt(i);
                    if (c != '-' && !Character.isLetter(c) && !Character.isDigit(c)) {
                        return "用户名包含非法字符，应由数字、英文字母、连字符 构成";
                    }
                }

                return null;
            }
        } else {
            return "用户名为空";
        }
    }

    public static String validateName(String name) {
        return name != null && !"".equals(name) && name.length() <= 10 ? null : "昵称为1到10个字符";
    }

    public static String validatePassword(String password) {
        if (password != null && !"".equals(password)) {
            if (password.length() >= 8 && password.length() <= 16) {
                String symbol = "!@#$%^&*()[]{}-_=+";
                boolean haveLetter = false;
                boolean haveDigit = false;
                boolean haveSymbol = false;

                for(int i = 0; i < password.length(); ++i) {
                    char c = password.charAt(i);
                    if (Character.isLetter(c)) {
                        haveLetter = true;
                    } else if (Character.isDigit(c)) {
                        haveDigit = true;
                    } else {
                        if (symbol.indexOf(c) == -1) {
                            return "密码包含非法字符" + c;
                        }

                        haveSymbol = true;
                    }
                }

                if (haveLetter && haveDigit && haveSymbol) {
                    return null;
                } else {
                    return "密码至少包含一个字母、一个数字、一个特殊符号";
                }
            } else {
                return "密码为8到16位";
            }
        } else {
            return "密码为空";
        }
    }

    public static String validateEmail(String email) {
        if (email != null && !"".equals(email)) {
            if (email.length() > 60) {
                return "邮箱最多为60个字符";
            } else {
                return email.matches("^([a-z0-9A-Z]+[-|\\.]?)+[a-z0-9A-Z]@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\\.)+[a-zA-Z]{2,}$") ? null : "邮箱格式不正确";
            }
        } else {
            return "邮箱为空";
        }
    }

    public static String validateIntro(String intro) {
        if (intro != null && !"".equals(intro)) {
            return intro.length() > 256 ? "简介为1到256个字符" : null;
        } else {
            return "简介为空";
        }
    }

    public static String validateSex(String sex) {
        return sex != null && ("男".equals(sex) || "女".equals(sex) || "保密".equals(sex)) ? null : "请选择性别";
    }
}
