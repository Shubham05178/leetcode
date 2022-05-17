class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        emailsSet = set()
        for email in emails:
            localname, domain = email.split("@")
            remainlocalname = localname.split("+")
            name = remainlocalname[0].replace(".","")   
            name += "@" + domain
            emailsSet.add(name)
        return len(emailsSet)